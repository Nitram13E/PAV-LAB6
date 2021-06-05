#include "header/CEnvioMensaje.h"

//TODO: clean the code



DtParticipacion * ctodtParticipacion(Participacion * par)
{
      if (par == NULL) return NULL;

      DtParticipacion * new_dtparticipacion = new DtParticipacion(par -> getId(),
                                                                  par -> getFecha(),
                                                                  par ->getMensaje(),
                                                                  ctodtParticipacion(par -> getResponde())
                                                                  );
      return new_dtparticipacion;
}

CEnvioMensaje::CEnvioMensaje()
{
      //se inicializa id_response en el constructor con el siguiente objetivo:
      // -1 se utiliza como valor nulo, si id_response == -1, entonces no es un mensaje de respuesta
      this -> id_response = -1;
}

CEnvioMensaje::~CEnvioMensaje(){}

std::list<int> CEnvioMensaje::clasesOnlineAsistiendo(std::string email)
{
      std::list<int> clases_asistiendo;
      //primero corrobar que el perfil exista
      bool existeUsuario = ManejadorPerfil::getInstancia() -> existePerfil(email);

      if(!existeUsuario)
      {
            return std::list<int>();
      }
      else
      {
            //si el perfil existe se busca y se guarda en perfil_usuario
            Perfil * perfil_usuario = ManejadorPerfil::getInstancia() -> buscarPerfil(email);

            if (dynamic_cast<Estudiante*>(perfil_usuario) != NULL) //si el perfil buscado es un estudiante
            {
                  Estudiante * estudiante = dynamic_cast<Estudiante*>(perfil_usuario);
                  std::list<Asignatura*> lista_asignaturas = estudiante -> getAsignaturas();

                  //En cada asignatura, se busca si en una clase en vivo se encuentra el estudiante y se devuelve el id de la clase

                  //se recorren las asignaturas del estudiante
                  for (std::list<Asignatura*>::iterator it = lista_asignaturas.begin(); it != lista_asignaturas.end(); it++)
                  {
                        //se recorre cada clase de cada asignatura
                        std::list<Clase*> lista_clases_it = (*it) -> getClases();
                        for (std::list<Clase*>::iterator it_c = lista_clases_it.begin(); it_c != lista_clases_it.end(); it_c++)
                        {
                              //se recorren las clases en vivo hasta encontrar al estudiante
                              std::list<AsisteVivo*> lista_asistevivo_it_c = (*it_c) -> getAsisteVivo();
                              std::list<AsisteVivo*>::iterator it_av = lista_asistevivo_it_c.begin();

                              while ((*it_av) -> getEstudiante() -> getEmail().compare(email) != 0 && it_av != lista_asistevivo_it_c.end())
                              {
                                    it_av++;
                              }

                              //al encontrarse el estudiante se devuelve el id de la clase en la posicion it_c
                              if((*it_av) -> getEstudiante() -> getEmail().compare(email) == 0)
                                    clases_asistiendo.push_back((*it_c) -> getID());
                        }
                  }
            }
            else //si es docente
            {
                  Docente * docente = dynamic_cast<Docente *>(perfil_usuario);

                  //se itera por cada rol que el docente cumple en determinada asignatura
                  std::list<Rol*> roles_docente =  docente -> getRoles();

                  for(std::list<Rol*>::iterator it = roles_docente.begin(); it != roles_docente.end(); it++)
                  {
                        //De la asignatura que tiene rol, se toman la lista de clases y se devueleven las mismas
                        //Se devuelven todas las clases por rol ya que se asume que si el docente tiene una clase es porque esta participando en la misma

                        std::list<Clase*> clasesXasig_rol = (*it) -> getAsignatura() -> getClases();
                        
                        for(std::list<Clase*>::iterator it = clasesXasig_rol.begin(); it != clasesXasig_rol.end(); it++)
                        {
                              clases_asistiendo.push_back((*it) -> getID());
                        }
                  }
            }
      }

      return clases_asistiendo;
}


std::list<DtParticipacion*> CEnvioMensaje::selectClase(int id_clase)
{
      //siendo que es una clase existente, de igual manera se comprueba si la clase existe, por seguridad.
      bool clase_existe = ManejadorClase::getInstancia() -> existeClase(id_clase);
      std::list<DtParticipacion*> participaciones_clase;

      if (!clase_existe)
      {
            return std::list<DtParticipacion*>();
      }
      else
      {     
            //se busca u devuelve la clase
            Clase * clase_seleccionada = ManejadorClase::getInstancia() -> buscarClase(id_clase);
            std::list<Participacion*> lista_participaciones = clase_seleccionada -> getParticipaciones();
            //el sistema recuerda la id de la clase buscada
            this -> id_clase = id_clase;

            //se recorre la lista de participaciones, se convierten en DataTypes y se devuelven para su visualizacion
            for (std::list<Participacion*>::iterator it = lista_participaciones.begin(); it != lista_participaciones.end(); it++)
            {
                  participaciones_clase.push_back(ctodtParticipacion(*it));
            }
      }

      return participaciones_clase;
}

void CEnvioMensaje::responder(int idParticipacion)
{     //el sistema recuerda la id del mensaje a responder
      this -> id_response = idParticipacion;
}

void CEnvioMensaje::ingresarTexto(std::string texto)
{     //el sistema recuerda el texto del mensaje ingresado
      this -> txt = texto;
}

void CEnvioMensaje::enviarMensaje()
{
      //se busca la clase a la que el futuro mensaje pertenece
      Clase * clase = ManejadorClase::getInstancia() -> buscarClase(this -> id_clase);
      
      //se crea una participacion a la cual responder, si la hay, se iguala la variable a la misma, de lo contrario, queda en nulo
      Participacion * to_response = NULL;
      
      //si id_response != -1 significa que hay un mensaje al cual responderle
      // se busca el mensaje y se lo guarda en to_response
      if (this -> id_response != -1)
      {
            std::list<Participacion*>::iterator it = clase -> getParticipaciones().begin();

            while((*it) -> getId() != this -> id_response && it != clase -> getParticipaciones().end())     it++;

            if ((*it) -> getId() == this -> id_response)    to_response = (*it);
      }

      //Participacion(DtTimeStamp, std::string, Participacion*);

      //se crea la participacion y se la agrega a la clase
      Participacion * newParticion = new Participacion(DtTimeStamp(DtFecha(12,12, 1980), 1 ,1, 1), this -> txt, to_response);

      clase -> getParticipaciones().push_back(newParticion);
}

void CEnvioMensaje::cancelar()
{
      //de cancelarse el CU, se reinician los valores
      this -> id_response = -1;
      this -> txt = "";
}