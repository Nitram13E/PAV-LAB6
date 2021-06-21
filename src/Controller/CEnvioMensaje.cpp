#include "header/CEnvioMensaje.h"
#include <ctime>

CEnvioMensaje::CEnvioMensaje()
{
    //se inicializa id_response en el constructor con el siguiente objetivo:
    // -1 se utiliza como valor nulo, si id_response == -1, entonces no es un mensaje de respuesta
    this -> id_response = -1;
}

CEnvioMensaje::~CEnvioMensaje(){}

DtParticipacion * CEnvioMensaje::ctodtParticipacion(Participacion * par)
{
    if(par == NULL) return NULL;
    DtParticipacion * new_dtparticipacion = new DtParticipacion(par -> getId(),
                                                                par -> getFecha(),
                                                                par ->getMensaje(),
                                                                ctodtParticipacion(par -> getResponde())
                                                                );
    return new_dtparticipacion;
}

std::list<int> CEnvioMensaje::clasesOnlineAsistiendo()
{
    std::list<int> clases_asistiendo;

    //Se llama al perfil que esta utilizando la sesion
    Sesion * sesion = Sesion::getInstancia();
    this -> perfil = sesion -> getPerfil();
    
    if (sesion -> getTipoPerfil() == ESTUDIANTE) //si el perfil es un estudiante
    {
        Estudiante * estudiante = dynamic_cast<Estudiante*>(this -> perfil);
        std::list<Asignatura*> lista_asignaturas = estudiante -> getAsignaturas();
        std::list<Asignatura*>::iterator it;

        for (it = lista_asignaturas.begin(); it != lista_asignaturas.end(); it++)
        {
            // Mueve los elementos que devuelve listarIdAsisteVivo() al final de la lista clases_asistiendo
            clases_asistiendo.splice(clases_asistiendo.end(), (*it) -> listarIdAsisteVivo());
        }
    }
    else if (sesion -> getTipoPerfil() == DOCENTE) //si es docente
    {
        Docente * docente = dynamic_cast<Docente *>(this -> perfil);

        //se itera por cada rol que el docente cumple en determinada asignatura
        std::list<Rol*> roles_docente = docente -> getRoles();
        std::list<Rol*>::iterator it;

        for (it = roles_docente.begin(); it != roles_docente.end(); it++)
        {
            // Mueve los elementos que devuelve listarIdAsisteVivo() al final de la lista clases_asistiendo
            clases_asistiendo.splice(clases_asistiendo.end(), (*it) -> getAsignatura() -> listarIdAsisteVivo());
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
        //se busca y guarda la clase
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
{    //el sistema recuerda la id del mensaje a responder
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
        std::list<Participacion*> participaciones = clase -> getParticipaciones();
        std::list<Participacion*>::iterator it = participaciones.begin();

        while(it != participaciones.end() && (*it) -> getId() != this -> id_response) it++;

        if(it != participaciones.end()) to_response = (*it);
    }

    std::time_t tt;
    DtTimeStamp tiempo = DtTimeStamp(tt);

    //se crea la participacion y se la agrega a la clase
    Participacion * newParticion = new Participacion(this -> perfil, tiempo, this -> txt, to_response);
    
    clase -> addParticipacion(newParticion);
}

void CEnvioMensaje::cancelar()
{
    //de cancelarse el CU, se reinician los valores
    this -> id_response = -1;
}

void CEnvioMensaje::cargarDatos()
{
    ManejadorClase* mc = ManejadorClase::getInstancia();
    ManejadorPerfil* mp = ManejadorPerfil::getInstancia();
    Clase* clase;

    clase = mc -> buscarClase(1);
    clase -> addParticipacion(new Participacion(mp -> buscarPerfil("mail-e1"), DtTimeStamp(DtFecha(20,6,2021), 10, 15, 0), "buenas profe disculpe que llegue tarde", NULL));

    clase = mc -> buscarClase(1);
    clase -> addParticipacion(new Participacion(mp -> buscarPerfil("mail-e2"), DtTimeStamp(DtFecha(20,6,2021), 10, 16, 0), "buenas noches diras, felipe", NULL));

    clase = mc -> buscarClase(1);
    clase -> addParticipacion(new Participacion(mp -> buscarPerfil("mail-e1"), DtTimeStamp(DtFecha(20,6,2021), 10, 18, 0), "como se dice", NULL));

    clase = mc -> buscarClase(1);
    clase -> addParticipacion(new Participacion(mp -> buscarPerfil("mail-e2"), DtTimeStamp(DtFecha(20,6,2021), 10, 59, 0), "Bueno, vamos dejando por aca", NULL));

    clase = mc -> buscarClase(0);
    clase -> addParticipacion(new Participacion(mp -> buscarPerfil("mail-e3"), DtTimeStamp(DtFecha(20,6,2021), 11, 58, 0), "nos vemos profe gracias por la clase", NULL));

    clase = mc -> buscarClase(0);
    clase -> addParticipacion(new Participacion(mp -> buscarPerfil("mail-d2"), DtTimeStamp(DtFecha(20,6,2021), 11, 59, 0), "De nada estimado", NULL));
}