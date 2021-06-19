#include "Factory.h"
#include "Class/header/Sesion.h"
#include "Interfaces/IAltaAsignatura.h"
#include "Interfaces/IAltaUsuario.h"
#include "Interfaces/IAsignacionDocenteAsignatura.h"
#include "Interfaces/IAsistenciaClaseVivo.h"
#include "Interfaces/IEnvioMensaje.h"
#include "Interfaces/IEliminarAsignatura.h"
#include "Interfaces/IiniciarSesion.h"
#include "Interfaces/IinicioClase.h"
#include "Interfaces/IInscripcionAsignaturas.h"
#include "Interfaces/IListadoClase.h"

#include "DataTypes/header/DtFecha.h"
#include "DataTypes/header/DtAsistir.h"
#include "DataTypes/header/DtPerfil.h"
#include "DataTypes/header/DtTimeStamp.h"
#include "DataTypes/header/DtInstanciaClase.h"
#include "DataTypes/header/DtAsignatura.h"
#include "DataTypes/header/DtInfoClase.h"
#include "DataTypes/header/DtInfoTeorico.h"
#include "DataTypes/header/DtInfoMonitoreo.h"
#include "DataTypes/header/DtIniciarClase.h"
#include "DataTypes/header/DtIniciarClaseFull.h"
#include "DataTypes/header/DtIniciarMonitoreo.h"
#include "DataTypes/header/DtParticipacion.h"
#include "Handlers/header/ManejadorPerfil.h"

#include "Handlers/header/ManejadorClase.h"
#include "Handlers/header/ManejadorAsignatura.h"

#include <unistd.h>

void menu();
void pressEnter();
void cargarDatos();
void bubbleMsg(DtParticipacion);
bool CUIniciarSesion();
void CUAltaUsuario();
void CUAltaAsignatura();
void CUAsignacionDocenteAsignatura();
void CUInicioClase();
void CUAsistenciaClaseVivo();
void CUEnvioMensaje();
void CUInscripcionAsignaturas();
void CUListadoClase();
void CUEliminarAsignatura();

Factory* fabrica = Factory::getInstancia();
IiniciarSesion* IIS;
IAltaUsuario* IAU;
IAsignacionDocenteAsignatura * IADA;
IAsistenciaClaseVivo* IACV;
IAltaAsignatura * IAA;
IInscripcionesAsignaturas * IIA;
IEnvioMensaje * IEM;
IEliminarAsignatura * IEA;
IinicioClase * IIC;
IListadoClases * ILC;

void menu()
{
    setlocale(LC_ALL, "");

    int op;
    bool inicio;

    system("clear");
    std::cout << "\n\tBienvenido!\n" << std::endl;
    std::cout << "1) Iniciar Sesion" << std::endl;
    std::cout << "2) Registrarse" << std::endl;
    std::cout << "\nElija una opción: ";
    std::cin >> op;

    if(op == 1) inicio = CUIniciarSesion();
    else if(op == 2)
    {
        CUAltaUsuario();
        inicio = CUIniciarSesion();
    }
    if(op == 3 || inicio) // Si el usuario ingreso en modo administrador (op = 3) o si inicio sesion exitosamente
    {
        do
        {
            system("clear");
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "\n\t\tBienvenido a TecnoinfClass\n" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "1.Alta de usuario" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "2.Alta de asignatura" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "3.Asignación de docentes a una asignatura" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "4.Inscripción a las asignaturas" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "5.Iniciar clase" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "6.Asistencia clase en vivo" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "7.Enviar mensaje" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "8.Eliminar asignatura" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "9.Listar clases" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "10.Cargar datos de prueba" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "11.Salir" << std::endl;
            std::cout << "---------------------------------------------------------" << std::endl;
            std::cout << "Opción: ";
            std::cin >> op;

            switch(op)
            {
                case 1: // Alta de usuario
                    CUAltaUsuario();
                    break;

                case 2: // Alta de asignatura
                    CUAltaAsignatura();
                    break;

                case 3: // Asignación de docentes a una asignatura
                    CUAsignacionDocenteAsignatura();
                    break;

                case 4: //Inscripción a las asignaturas
                    CUInscripcionAsignaturas();
                    break;
                
                case 5: //Inicio de clase
                    CUInicioClase();
                    break;

                case 6: // Asistencia a clase en vivo
                    CUAsistenciaClaseVivo();
                    break;

                case 7: //Envío de mensaje
                    CUEnvioMensaje();
                    break;

                case 8: //Eliminación de asignatura
                    CUEliminarAsignatura();
                    break;

                case 9: //Listado de Clases
                    CUListadoClase();
                    break;

                case 10: //cargar datos
                    cargarDatos();
                    break;

                case 11: // Salir
                    std::cout << "\nSaliendo..." << std::endl;
                    sleep(2);
                    break;

                default:
                    std::cout << "\nPor favor, introduzca una opcion valida." << std::endl;
                    pressEnter();
                    system("clear");
            }
        }
        while (op != 11);
    }
}

void pressEnter()
{
    std::string enter;
    std::getline(std::cin, enter);
    std::cout << "Presiona enter para continuar...";
    std::getline(std::cin, enter);
}

void cargarDatos()
{
    IAU = fabrica -> getIAltaUsuario();

    //ALTA USUARIO
    IAU -> ingresarDatosPerfil(DtPerfil("EST1", "IMG1", "mail-e1", "123abc"), ESTUDIANTE);
    IAU -> ingresarEstudiante("342342");
    IAU -> altaUsuario();

    IAU -> ingresarDatosPerfil(DtPerfil("EST2", "IMG2", "mail-e2", "123abc"), ESTUDIANTE);
    IAU -> ingresarEstudiante("3878424");
    IAU -> altaUsuario();

    IAU -> ingresarDatosPerfil(DtPerfil("EST3", "IMG3", "mail-e3", "123abc"), ESTUDIANTE);
    IAU -> ingresarEstudiante("6565624");
    IAU -> altaUsuario(); 

    IAU -> ingresarDatosPerfil(DtPerfil("EST4", "IMG4", "mail-e4", "123abc"), ESTUDIANTE);
    IAU -> ingresarEstudiante("342342");
    IAU -> altaUsuario();

    IAU -> ingresarDatosPerfil(DtPerfil("EST5", "IMG5", "mail-e5", "123abc"), ESTUDIANTE);
    IAU -> ingresarEstudiante("3878424");
    IAU -> altaUsuario();

    IAU -> ingresarDatosPerfil(DtPerfil("EST6", "IMG6", "mail-e6", "123abc"), ESTUDIANTE);
    IAU -> ingresarEstudiante("6565624");
    IAU -> altaUsuario();


    IAU -> ingresarDatosPerfil(DtPerfil("DOC1", "IMG1", "mail-d1", "123abc"), DOCENTE);
    IAU -> ingresarDocente("ins1");
    IAU -> altaUsuario();

    IAU -> ingresarDatosPerfil(DtPerfil("DOC2", "IMG2", "mail-d2", "123abc"), DOCENTE);
    IAU -> ingresarDocente("ins2");
    IAU -> altaUsuario();

    IAU -> ingresarDatosPerfil(DtPerfil("DOC3", "IMG3", "mail-d3", "123abc"), DOCENTE);
    IAU -> ingresarDocente("ins1");
    IAU -> altaUsuario();

    IAU -> ingresarDatosPerfil(DtPerfil("DOC4", "IMG4", "mail-d4", "123abc"), DOCENTE);
    IAU -> ingresarDocente("ins2");
    IAU -> altaUsuario();

    //ALTA ASIGNATURA
    IAA = fabrica -> getIAltaAsignatura();

    IAA -> ingresar(new DtAsignatura("1", "PAV", new DtInstanciaClase(true, true, true)));
    IAA -> altaAsignatura();

    IAA -> ingresar(new DtAsignatura("2", "COE", new DtInstanciaClase(true, true, false)));
    IAA -> altaAsignatura();
    
    IAA -> ingresar(new DtAsignatura("3", "CONT", new DtInstanciaClase(false, true, false)));
    IAA -> altaAsignatura();

    IAA -> ingresar(new DtAsignatura("4", "BD II", new DtInstanciaClase(true, true, false)));
    IAA -> altaAsignatura();

    IAA -> ingresar(new DtAsignatura("5", "RC", new DtInstanciaClase(true, false, true)));
    IAA -> altaAsignatura();

    IAA -> ingresar(new DtAsignatura("6", "BD I", new DtInstanciaClase(false, true, false)));
    IAA -> altaAsignatura();

    //Asignar Docentes
    
    IADA = fabrica -> getIAsignacionDocenteAsignatura();

    IADA -> docentesSinLaAsignatura("1");
    IADA -> selectDocente("mail-d1", TEORICO);
    IADA -> asignarDocente();

    IADA -> docentesSinLaAsignatura("1");
    IADA -> selectDocente("mail-d2", PRACTICO);
    IADA -> asignarDocente();

    IADA -> docentesSinLaAsignatura("2");
    IADA -> selectDocente("mail-d3", TEORICO);
    IADA -> asignarDocente();

    IADA -> docentesSinLaAsignatura("3");
    IADA -> selectDocente("mail-d4", PRACTICO);
    IADA -> asignarDocente();

    IADA -> docentesSinLaAsignatura("4");
    IADA -> selectDocente("mail-d3", TEORICO);
    IADA -> asignarDocente();

    IADA -> docentesSinLaAsignatura("4");
    IADA -> selectDocente("mail-d1", PRACTICO);
    IADA -> asignarDocente();

    IADA -> docentesSinLaAsignatura("5");
    IADA -> selectDocente("mail-d2", TEORICO);
    IADA -> asignarDocente();

    IADA -> docentesSinLaAsignatura("5");
    IADA -> selectDocente("mail-d1", MONITOREO);
    IADA -> asignarDocente();

    IADA -> docentesSinLaAsignatura("6");
    IADA -> selectDocente("mail-d3", PRACTICO);
    IADA -> asignarDocente();
    
    Asignatura * asig = ManejadorAsignatura::getInstancia() -> buscarAsignatura("1"); 
    ManejadorPerfil * mp = ManejadorPerfil::getInstancia();
    Estudiante * est = dynamic_cast<Estudiante *>(mp -> buscarPerfil("mail-e1"));
    est -> addAsignaturas(asig);
    
    Practico * pr = new Practico("PAv Practico", DtTimeStamp(DtFecha(21,6,2021), 10, 00 , 00), NULL, "");
    pr -> addDocentes(dynamic_cast<Docente *>(mp -> buscarPerfil("mail-d2")));
    ManejadorClase::getInstancia() -> addClase(pr);
    asig -> addClases(pr);

    //Creacion de mensaje para clase agregada
    Participacion * msj = new Participacion(DtTimeStamp(DtFecha(21,6,2021), 10, 05 , 00),"Bienvenidos",NULL);
    pr -> addParticipacion(msj);

    //Iniciar Clases
    /**IIC = fabrica -> getIinicioClase();
    
    IIC -> selectAsignatura(DtIniciarClase("", "", DtTimeStamp(DtFecha(), 0, 0, 0)));
    IIC -> datosIngresados();
    IIC -> iniciarClase();

    //Inscripcion Asignaturas
    Sesion * sesion = Sesion::getInstancia();
   
    if(sesion -> getTipoPerfil() == ESTUDIANTE)
    {
        IIA = fabrica -> getInscripcionAsignaturas();

        IIA -> selectAsignatura("1");
        IIA -> inscribir();

        IIA -> selectAsignatura("2");
        IIA -> inscribir();

        IIA -> selectAsignatura("3");
        IIA -> inscribir();

        IIA -> selectAsignatura("4");
        IIA -> inscribir();

        IIA -> selectAsignatura("5");
        IIA -> inscribir();
    }**/
    
    //Enviar Mensaje

    system("clear");
    std::cout << "\nDatos cargados.\n" << std::endl;
    pressEnter();
}

//Crea burbuja para mensaje
void bubbleMsg(DtParticipacion * msg)
{
	for (int i = 0; i < msg -> getMensaje().length() + 7; i++)
	{
		std::cout << "_";
	}
	std::cout << "\n";
	
	std::cout << "(";
	std::cout << msg -> getFecha().getHora() << ":" << msg -> getFecha().getMinuto() << ")";
    std::cout << "\t[id: " << msg -> getId() << "]" << std::endl;
	std::cout << "|/";
	
	for (int i = 0; i < msg ->getMensaje().length() + 7; i++)
	{
		std::cout << "¯";
	}
	
	std::cout << "\n";
}

int main()
{
    menu();

    return 0;
}

bool CUIniciarSesion()
{
    IIS = fabrica -> getIiniciarSesion();
    std::string email;
    std::string password;

    bool inicio = false;
    int intentos = 5;
    
    do
    {
        system("clear");
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "\t\tIniciar Sesion:" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Contraseña: ";
        std::cin >> password;

        IIS -> ingresarEmail(email);

        if(IIS -> validarContrasenia(password))
        {
            IIS -> inciarSesion();
            inicio = true;
        }
        else
        {
            intentos--;
            std::cout << "\nContraseña incorrecta. Intentos restantes: "<< intentos << std::endl;
            sleep(1);
        }
    }while(!inicio && intentos > 0);

    return inicio;
}

void CUAltaUsuario()
{
    IAU = fabrica -> getIAltaUsuario();

    std::string nom;
    std::string imgURL;
    std::string email;
    std::string pass;

    std::string opAU;

    do
    {
        // ingresarDatosPerfil
        system("clear");
        std::cout << "Alta Usuario" << std::endl << std::endl;
        std::cout << "Ingrese nombre: ";
        std::cin >> nom;
        system("clear");

        std::cout << "Ingrese imagen: ";
        std::cin >> imgURL;
        system("clear");

        std::cout << "Ingrese email: ";
        std::cin >> email;
        system("clear");

        std::cout << "Ingrese contraseña: ";
        std::cin >> pass;
        system("clear");
        
        DtPerfil perfil = DtPerfil(nom, imgURL, email, pass);

        int op;

        std::cout << "Elija el tipo de perfil:" << std::endl;
        std::cout << "- Estudiante '0'" << std::endl;
        std::cout << "- Docente '1'" << std::endl;
        std::cout << "Opción: ";
        std::cin >> op;

        switch (op)
        {
            case 0: // Es estudiante
            {
                // ingresarEstudiante
                std::string ci;
                std::cout << "Ingrese CI: ";
                std::cin >> ci;

                IAU -> ingresarDatosPerfil(perfil, ESTUDIANTE);
                IAU -> ingresarEstudiante(ci);
                break;
            }
            case 1: // Es docente
            {
                // ingresarDocente
                std::string ins;
                std::cout << "Ingrese instituto: ";
                std::cin >> ins;

                IAU -> ingresarDatosPerfil(perfil, DOCENTE);
                IAU -> ingresarDocente(ins);
                break;
            }
            default:
                std::cout << "Por favor, ingrese una de las opciones." << std::endl;
        }
        // AltaUsuario
        std::string confirmar;
        std::cout << "Desea agregar el perfil? [S/N o Cualquier letra (menos la s)]: ";
        std::cin >> confirmar;

        if(confirmar == "S" || confirmar == "s")
        {
            IAU -> altaUsuario();
        }
        // [Quiere agregar usuario]
        system("clear");
        std::cout << "Desea crear un nuevo usuario? [S/N]: ";
        std::cin >> opAU;

    }while(opAU == "S" || opAU == "s");
}

void CUAltaAsignatura()
{
    IAA = fabrica -> getIAltaAsignatura();

    std::string codigo;
    std::string nombre;
    DtInstanciaClase* tipo;

    bool teorico = false;
    bool practico = false;
    bool monitoreo = false;

    system("clear");
    std::cout << "\t\tAlta Asignatura\n" << std::endl;
    std::cout << "Ingrese código: ";
    std::cin >> codigo;
    system("clear");
    std::cout << "Ingrese nombre: ";
    std::cin >> nombre;
    system("clear");
    
    std::string op;

    std::cout << "La asignatura tendrá clases de teorico? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> op;
    if(op == "S" || op == "s") teorico = true;

    std::cout << "La asignatura tendrá clases de practico? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> op;
    if(op == "S" || op == "s") practico = true;

    std::cout << "La asignatura tendrá clases de monitoreo? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> op;
    if(op == "S" || op == "s") monitoreo = true;

    tipo = new DtInstanciaClase(teorico, practico, monitoreo);

    DtAsignatura* dtAsig = new DtAsignatura(codigo, nombre, tipo);

    // AltaAsignatura
    DtAsignatura* datos = IAA -> ingresar(dtAsig);

    std::cout << *datos << std::endl;

    std::string confirmar;
    std::cout << "\nDesea agregar la asignatura? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> confirmar;
    if(confirmar == "S" || confirmar == "s") IAA -> altaAsignatura();
    else IAA -> cancelar();
}

void CUAsignacionDocenteAsignatura()
{
    IADA = fabrica -> getIAsignacionDocenteAsignatura();

    std::string codigo;
    std::string email;
    int r;
    tipoRol rol;
    
    std::string op;
    std::string confirmar;
    
    do
    {
        std::cout << "\t\tAsignacion de un Docente a una Asignatura\n" << std::endl;

        std::list<std::string> asignaturas = IADA -> listarAsignaturas();
        
        std::cout << "Asignaturas: " << std::endl;
        for(std::list<std::string>::iterator it = asignaturas.begin(); it != asignaturas.end(); it++)
        {
            std::cout << *it << std::endl;
        }
        
        std::cout << "Seleccione una asignatura: ";
        std:: cin >> codigo;
        system("clear");

        std::list<std::string> docentes = IADA -> docentesSinLaAsignatura(codigo);

        std::cout << "Docentes no asignados: " << std::endl;
        for(std::list<std::string>::iterator i = docentes.begin(); i != docentes.end(); i++)
        {
            std::cout << *i << std::endl;
        }

        std::cout << "Seleccione un docente: ";
        std:: cin >> email;
        system("clear");
        
        std::cout << "Asigne un rol: " << std::endl;
        std::cout << "1: Teorico" << std::endl;
        std::cout << "2: Practico" << std::endl;
        std::cout << "3: Monitoreo" << std::endl;
        std::cout << "Opción: ";
        std:: cin >> r;

        switch (r)
        {
        case 1:
            rol = TEORICO;
            break;
        
        case 2:
            rol = PRACTICO;
            break;

        case 3:
            rol = MONITOREO;
            break;

        default:
            std::cout << "Opción incorrecta. " << std::endl;
            pressEnter();
            op = "e";
            break;
        }
        
        if(op != "e")
        {
            system("clear");

            IADA -> selectDocente(email, rol);
            
            std::cout << "Desea confirmar? [S/N]: ";
            std::cin >> confirmar;

            if(confirmar == "S" || confirmar == "s")
            {
                try
                {
                    IADA -> asignarDocente();
                }
                catch(const std::invalid_argument& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
            else IADA -> cancelar();
            system("clear");

            std::cout << "Desea continuar agregando docentes? [S/N]: ";
            std::cin >> op;

            docentes.empty();
            system("clear");
        }
    }while(op == "S");
}

void CUInicioClase()
{
    IIC = fabrica -> getIinicioClase();
    std::string codAsig;
    std::string nombre;
    DtIniciarClase inicio;

    std::list<std::string> asignaturasAsignadas = IIC -> asignaturasAsignadas();

    std::list<std::string>::iterator it;

    std::cout << "Inicio Clase" << std::endl;
    std::cout << "Asignaturas Asignadas: " << std::endl;

    if(asignaturasAsignadas.empty())
    {
        std::cout << "La asignatura no contiene clases. " << std::endl;
        pressEnter();
    }
    else
    {
        for(it = asignaturasAsignadas.begin(); it != asignaturasAsignadas.end(); it++) std::cout << (*it) << std::endl;

        std::cout << "Seleccione una de las Asignaturas: ";
        std::cin >> codAsig;
        std::cout << "Ingrese nombre de la clase: ";
        std::cin >> nombre;

        time_t time;
        inicio = DtIniciarClase(codAsig, nombre, DtTimeStamp(time));
        std::string op;

        if(IIC -> selectAsignatura(inicio))
        {
            std::list<std::string> inscriptos = IIC -> inscriptosAsignatura();
            std::list<std::string>::iterator it;

            std::cout << "Estudiantes inscriptos a la asignatura " << codAsig << ":" << std::endl;

            for(it = inscriptos.begin(); it != inscriptos.end(); it++)
            {
                std::cout << " - " << *it << std::endl;
            }

            do
            {
                std::string email;
                std::cout << "Ingrese mail de alumno a habilitar: " << std::endl;
                std::cin >> email;
                std::cout << email << std::endl; //prueba

                IIC -> habilitar(email);

                std::cout << "Desea agregar otro alumno? [S/N o Cualquier letra (menos la s)]: ";
                std::cin >> op;

            }while(op == "S" || op == "s");
        }
        std::cout << *(IIC -> datosIngresados()) << std::endl;

        std::cout << "Desea confirmar los datos ingresados? [S/N o Cualquier letra (menos la s)]: ";
        std::cin >> op;

        if(op == "S" || op == "s") IIC -> iniciarClase();
        else IIC -> cancelar();
    }
}

void CUAsistenciaClaseVivo()
{
    IACV = fabrica -> getIAsistenciaClaseVivo();

    std::string codigo;
    int id;
    std::string confirmar;

    std::list<std::string> inscr = IACV -> asignaturasInscriptos();
    std::cout << "Asignaturas cursando: " << std::endl;

    for(std::list<std::string>::iterator it = inscr.begin(); it != inscr.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Seleccione una asignatura: ";
    std::cin >> codigo;
    system("clear");

    std::list<int> cDisp = IACV -> clasesOnlineDisponibles(codigo);
    std::cout << "Clases disponibles: \n" << std::endl;
    for(std::list<int>::iterator it = cDisp.begin(); it != cDisp.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "Seleccione una clase: ";
    std::cin >> id;
    system("clear");
    
    DtAsistir* asist = IACV -> selectClase(id);
    std::cout << "Datos Ingresados: " << std::endl;
    std::cout << *asist << std::endl;

    std::cout << "Desea confirmar? [S/N]" << std::endl;
    std::cin >> confirmar; 
    if(confirmar == "S" || confirmar == "s")
    {
        IACV -> asistirClaseVivo();
        std::cout << "\nSu clase comenzara pronto....\n";
        pressEnter();
    } 
    else
    {
        IACV -> cancelar();
        std::cout << "\nUsted ha cancelado\n";
    }
}

void CUEnvioMensaje()
{
    int id_selected, id_response;
    std::string txt;

    IEM = fabrica -> getIEnvioMensaje();

    std::list<int> clasesVivo = IEM -> clasesOnlineAsistiendo();
    std::list<int>::iterator it;

    std::list<DtParticipacion*> participaciones;
    std::list<DtParticipacion*>::iterator it_p;

    std::cout << "\nClases en vivo:\n\n";

    for (it = clasesVivo.begin(); it != clasesVivo.end(); it++)
    {
        std::cout << " - " << *it << "\n";
    }

    do
    {
        system("clear");
        std::cout << "\nSeleccionar clase: ";
        std::cin >> id_selected;

        it = clasesVivo.begin();

        while (*it != id_selected && it != clasesVivo.end())
        {
            it++;
        }

    } while (it == clasesVivo.end());
    
    participaciones = IEM -> selectClase(id_selected);

    std::cout << "\nParticipaciones:\n\n";

    for (it_p = participaciones.begin(); it_p != participaciones.end(); it_p++)
    {

         bubbleMsg((*it_p));

        if ((*it_p) -> getResponde() != NULL)
        {
            std::cout << "Responde a:\n";
            bubbleMsg((*it_p) -> getResponde());
        }

        std::cout << "------------------------------------------------------------" << std::endl;
    }

    std::string confirmar;
    std::cout << "Desea contestar alguna participacion? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> confirmar;

    if(confirmar == "S" || confirmar == "s")
    {
        do
        {
            //system("clear");
            std::cout << "\n id de la participacion a responder: ";
            std::cin >> id_response;

            it_p = participaciones.begin();

            while ((*it_p) -> getId() != id_response && it_p != participaciones.end())
            {
                it_p++;
            }
        } while (it_p == participaciones.end());
        
        IEM ->responder(id_response);
    }

        std::cout << "\n Ingrese texto: ";
        std::cin >> txt;
        IEM -> ingresarTexto(txt);

    std::cout << "Seguro que quiere enviar la participacion? (Verifique que no sea un insulto al docente)[S/N o Cualquier letra (menos la s)]: ";
    std::cin >> confirmar;
    
    if(confirmar == "S" || confirmar == "s")
    {
        IEM -> enviarMensaje();
    }
    else
    {
        IEM -> cancelar();
    }
}

void CUInscripcionAsignaturas()
{
    IIA = fabrica -> getInscripcionAsignaturas();

    std::string codigoAsig;
    int op = 0;

    do
    {
        std::list<std::string> listaAsignaturas = IIA -> asignaturasNoInscriptos();
        std::list<std::string>::iterator it;

        if(listaAsignaturas.empty())
        {
            std::cout << "\nNo hay asignaturas disponibles a las cuales inscribirse.\n" << std::endl;

            op = 3;

            pressEnter();
        }
        else
        {
            system("clear");
            std::cout << "Asignaturas disponibles:" << std::endl;
            //Muestro las asignaturas en las cuales el estudiante no esta inscripto
            for (it = listaAsignaturas.begin(); it != listaAsignaturas.end(); it++)
            {
                std::cout << *it << std::endl;
            }

            std::cout << "Seleccione la asignatura a inscribirse: ";
            std::cin >> codigoAsig;

            IIA -> selectAsignatura(codigoAsig);

            std::cout << "1: Inscribirse" << std::endl << "2: Cancelar "<< std::endl;
            std::cout << "Ingrese una opcion: ";
            std::cin >> op;

            if(op == 1)
            {
                IIA -> inscribir();
            }

            std::string confirmar;
            std::cout << "Desea continuar inscribiendose a asignaturas? [S/N o Cualquier letra (menos la s)]: ";
            std::cin >> confirmar;
            if(confirmar == "N" || confirmar == "n") op = 3;
        }
    }while(op != 3);
}

void CUListadoClase()
{
    ILC = fabrica->getIListadoClase();
    
    std::list<std::string> clasesDelDocente = ILC -> asignaturasAsignadas();
    std::list<std::string>::iterator it;

    std::list<DtInfoClase*> infoClases;
    std::list<DtInfoClase*>::iterator itClases;

    int counter = 0;
    std::string opcion;
    
    if(!clasesDelDocente.empty())   //lista no vacia
    {
        std::cout << "Seleccione una de las siguientes asignaturas que esta asignado: " << std::endl;
        
        for(it = clasesDelDocente.begin(); it != clasesDelDocente.end(); ++it)
        {
            std::cout << counter+1 << ") " << (*it) << std::endl;
        }
        
        std::cout << std::endl <<"Opción: ";
        std::cin >> opcion;

        infoClases = ILC -> selectAsignatura(opcion);

        system("clear");
        std::cout << "Informacion de la Clase:" << std::endl;

        for(itClases = infoClases.begin(); itClases != infoClases.end(); itClases++) //hacer un dynamic cast sis DtInfoClaseMonitoreo o Teorico o Practico
        {
            try
            {
                DtInfoTeorico* infoTeorico = dynamic_cast<DtInfoTeorico*>(*itClases);
                std::cout << *infoTeorico << std::endl;
            }
            catch(const std::bad_cast* e)
            {
                DtInfoMonitoreo* infoMonitoreo = dynamic_cast<DtInfoMonitoreo*>(*itClases);
                std::cout << *infoMonitoreo << std::endl;
            }
            catch(const std::bad_cast* error)
            {
                std::cout << *(*itClases) << std::endl;
            }

            /**
            if(infoTeorico != NULL)
            {
                std::cout << infoTeorico << std::endl;
            }
            else
            {
                

                if(infoMonitoreo != NULL) std::cout << infoMonitoreo << std::endl;

                else 
            }
            **/
            //std::cout <<  << std::endl;
        }

        pressEnter();
    }
    else
    {
        std::cout << "El docente no tiene clases. " << std::endl;
        pressEnter();
    }
}

void CUEliminarAsignatura()
{
    IEA = fabrica -> getIEliminarAsignatura();

    std::cout << "\t\tEliminar Asignatura: " << std::endl;
    std::list<std::string> listarAsignaturas = IEA ->  listarAsignaturas();
    std::list<std::string>::iterator it;
    std::string opcion;

    for(it = listarAsignaturas.begin(); it != listarAsignaturas.end(); it++)
    {
        std::cout << " - " << *it << std::endl;

    }

    std::cout << "Seleccione una Asignatura: ";
    std::cin >> opcion;
    system("clear");

    IEA -> selectAsignatura(opcion);

    std::cout << "Desea confirmar? [S/N o Cualquier letra (menos la s)]: ";
    std::cin >> opcion;

    if (opcion =="S" || opcion == "s")
    {
        IEA -> eliminarAsignatura();
        std::cout << "Se ha eliminado la asignatura exitosamente" << std::endl;
    }
    else std::cout <<"Operación cancelada." << std::endl;
}
