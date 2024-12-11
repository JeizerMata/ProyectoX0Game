#include <iostream>

#include <string>

#include <cstdlib>

#include <ctime>

#include <windows.h>



using namespace std;



// Declarando funciones

void mostrarTablero(const char tablero[]); 

bool verificarGanador(const char tablero[], char jugador);

bool tableroLleno(const char tablero[]);

int obtenerMovimientoComputadora(const char tablero[]);

void mostrarBienvenida();

void mostrarMenu();

void reiniciarTablero(char tablero[]);

void cambiarColor(int color);

void limpiarPantalla();



    // Sistema de Login

    const string contrasenaCorrecta = "0000";

    string usuario, contrasena;

    bool accesoConcedido = false;

    const int maxIntentos = 3;

    int intentos = 0;

    

int main() {

	cout << endl << endl << endl << endl << endl << endl << endl << endl;

	cambiarColor(11); // Aqua claro para  el marco

	//Rotulo principal del Inicio

	for (int i = 0; i < 120; i++) cout << char(219);

    cout << endl << endl;

    cout << "\033[36m                 ##     ##       ####          ############   ###########   ####     ####   ###########" << endl;

    cout << "\033[36m                  ##   ##      ##    ##        ##             ##       ##   ## ##   ## ##   ##" << endl;

    cout << "\033[36m                   ## ##      ##      ##       ##             ##       ##   ##  ## ##  ##   ##" << endl;

    cout << "\033[36m                    ###       ##      ##       ##    ######   ###########   ##   ###   ##   #######" << endl;

    cout << "\033[36m                   ## ##      ##      ##       ##        ##   ##       ##   ##         ##   ##" << endl;

    cout << "\033[36m                  ##   ##      ##    ##        ##        ##   ##       ##   ##         ##   ##" << endl;

    cout << "\033[36m                 ##     ##       ####          ############   ##       ##   ##         ##   ###########" << endl;

    cout << endl;

    cambiarColor(11); // Aqua claro para  el marco

    for (int i = 0; i < 120; i++) cout << char(219);

    cout << endl << endl;

    

    cambiarColor(0); // Cambia al color negro

    system("pause"); // Pausa hasta que el usuario presione una tecla

	limpiarPantalla(); // Limpia la pantalla antes de mostrar el login

    cambiarColor(7); // Vuelve al color original

    

    // Rotulo de logo de login

    cout << endl;

    cout << "	   				                #### " << endl;

    cout << "					              ##    ##" << endl;

    cout << "					            ##        ##" << endl;

    cout << "					           ##          ##" << endl;

    cout << "					           ##          ##" << endl;

    cout << "					            ##        ##" << endl;

    cout << "					              ##    ##" << endl;

    cout << "					                ####" << endl;

    cout << "					              ##    ##" << endl;

    cout << "					            ##         ##" << endl;

    cout << "					          ##             ##" << endl;

    cout << "					         ##               ##" << endl;

    cout << endl;

    

    cout << "                                                  === LOGIN X0 ===" << endl;

    

    while (intentos < maxIntentos && !accesoConcedido) {

    	cambiarColor(7); //vuelve al color original

        cout << "\n                                                   Usuario: ";

        cin >> usuario;

        cout << "                                                   Password: ";

        cin >> contrasena;



        if (contrasena == contrasenaCorrecta) {

            accesoConcedido = true;

        } else {

            intentos++;

            cout << "\033[34m                                 Usuario o password incorrectos\033[34m. Intento " << intentos << " de " << maxIntentos << "." << endl;

        }

    }



    if (!accesoConcedido) {

        cout << "\033[31m\n                                  Acceso denegado. Se han agotado los intentos.\033[0m" << endl;

        return 0; // Salir del programa si no se concede acceso

    }



    // Inicio del juego XO

    char tablero[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    char jugadorActual;

    char simboloJugador, simboloComputadora;

    bool ganador = false;

    int opcion;

    string jugadorX, jugadorO;



    while (true) {

        limpiarPantalla(); // Limpiar pantalla antes de mostrar menus

        mostrarBienvenida();

        mostrarMenu();

        

        //Menu principal

        cout << "\nElige una opcion: ";

        cambiarColor(11);

        cin >> opcion;

        cambiarColor(7);



        limpiarPantalla();



        if (opcion == 1) {

            // Jugar con un amigo

            cout << "Introduce el nombre del jugador X: ";

            cambiarColor(4);

            cin >> jugadorX;

            cambiarColor(7);

            cout << "Introduce el nombre del jugador O: ";

            cambiarColor(1);

            cin >> jugadorO;

            cambiarColor(7);

            jugadorActual = 'X';

        } else if (opcion == 2) {

            // Jugar con la mÃ¡quina

            cout << "Introduce tu nombre: ";

            cambiarColor(2);

            cin >> jugadorX;

            cambiarColor(7);

            jugadorO = "Chiken";



            char eleccion;

            cout << "Quieres ser X o 0 (cero)? ";

            cambiarColor(2);

            cin >> eleccion;

            cambiarColor(7);

            

            eleccion = toupper(eleccion);



            if (eleccion == 'X') {

                simboloJugador = 'X';

                simboloComputadora = '0';

                jugadorActual = 'X';

            } else if (eleccion == '0') {

                simboloJugador = '0';

                simboloComputadora = 'X';

                jugadorActual = 'X'; // La computadora empieza si el jugador elige '0'.

            } else {

                cout << "Eleccion invalida. Por defecto seras X." << endl;

                simboloJugador = 'X';

                simboloComputadora = '0';

                jugadorActual = 'X';

            }

        } else if (opcion == 3) {

            cout << "\033[33mSaliendo del juego... Hasta luego!\033[0m" << endl;

            return 0;

         } else {

            cout << "\033[31mOpcion invalida. Intenta de nuevo.\033[0m" << endl;

            continue;

        }



        reiniciarTablero(tablero);

        ganador = false;



        // Juego principal

        while (!ganador && !tableroLleno(tablero)) {

            mostrarTablero(tablero);



            int movimiento;

            if (opcion == 2 && jugadorActual == simboloComputadora) {

                // Turno de la computadora

                movimiento = obtenerMovimientoComputadora(tablero);

                cout << jugadorO << " elige la posicion " << movimiento + 1 << endl;

            } else if (opcion == 2 && jugadorActual == simboloJugador) {

                // Turno del usuario

                cout << "Turno de ";

                cambiarColor(6); // Amarillo para el nombre del jugador

                cout << jugadorX;

                cambiarColor(7); // Blanco predeterminado

                cout << " (";

                cambiarColor(6); // Amarillo para la ficha

                cout << jugadorActual;

                cambiarColor(7);

                cout << "). Elige una posicion (1-9): ";

                cin >> movimiento;

                movimiento--;

            } else {

                // Modo de juego entre dos amigos

                cout << "Turno de ";

                cambiarColor(6); // Amarillo para el nombre del jugador

                cout << (jugadorActual == 'X' ? jugadorX : jugadorO);

                cambiarColor(7); // Blanco predeterminado

                cout << " (";

                cambiarColor(6); // Amarillo para la ficha

                cout << jugadorActual;

                cambiarColor(7);

                cout << "). Elige una posicion (1-9): ";

                cin >> movimiento;

                movimiento--;

            }



            if (movimiento >= 0 && movimiento < 9 && tablero[movimiento] == ' ') {

                tablero[movimiento] = jugadorActual;

                ganador = verificarGanador(tablero, jugadorActual);

                jugadorActual = (jugadorActual == 'X') ? '0' : 'X';

            } else {

                cambiarColor(12); // Rojo para mensajes de error

                cout << "Esta casilla ya esta ocupada, Intenta de nuevo." << endl;

                cambiarColor(7); // Restaurar color original

                system("pause"); // Pausa para que el usuario pueda leer el mensaje

            }



            limpiarPantalla();

        }



        mostrarTablero(tablero);



        if (ganador) {

            cambiarColor(2); // Verde para mensaje de victoria

            cout << "\033[33m\nWINNER WINNER CHIKEN DINER, El jugador " << (jugadorActual == simboloJugador ? jugadorO : jugadorX) << " ha ganado!" << endl;

            cambiarColor(7);

        } else {

            cambiarColor(10); // Verde claro para empate

            cout << "\nEs un empate!" << endl;

            cambiarColor(7);

        }



        cout << "\n1. Jugar de nuevo" << endl;

        cout << "2. Salir" << endl;

        cout << "\nElige una opcion: ";

        int opcionFinal;

        cin >> opcionFinal;



        if (opcionFinal != 1) {

            cout << "\033[33mSaliendo del juego... Hasta luego!\033[0m" << endl;

            break;

        }

    }



    return 0;

}



// Funciones auxiliares

void mostrarBienvenida() {

    cambiarColor(10); // Magenta para bienvenida

    cout << "\n========================================================================================================================" << endl;

    cout << "                                         Bienvenido " << usuario << ", al juego XO " << endl;

    cout << "========================================================================================================================" << endl;

    cambiarColor(7);

}



void mostrarMenu() {

    cambiarColor(11); // Cian para menu

    cout << "\n=== MENU PRINCIPAL ===" << endl;

    cout << "1. Dos jugadores" << endl;

    cout << "2. Jugar contra la maquina" << endl;

    cout << "3. Salir" << endl;

    cambiarColor(7);

}



void mostrarTablero(const char tablero[]) {

    cout << "\n";

    for (int i = 0; i < 9; i++) {

        if (tablero[i] == 'X') {

            cambiarColor(12); // Rojo

        } else if (tablero[i] == '0') {

            cambiarColor(9); // Azul

        }

        cout << tablero[i];

        cambiarColor(7); // Blanco predeterminado



        if (i % 3 != 2) {

            cout << " | ";

        } else if (i < 8) {

            cout

            << "\n---------\n";

        }

    }

    cout << "\n";

}



bool verificarGanador(const char tablero[], char jugador) {

    int lineas[8][3] = {

        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},

        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},

        {0, 4, 8}, {2, 4, 6}

    };



    for (int i = 0; i < 8; i++) {

        if (tablero[lineas[i][0]] == jugador &&

            tablero[lineas[i][1]] == jugador &&

            tablero[lineas[i][2]] == jugador) {

            return true;

        }

    }

    return false;

}



bool tableroLleno(const char tablero[]) {

    for (int i = 0; i < 9; i++) {

        if (tablero[i] == ' ') {

            return false;

        }

    }

    return true;

}



int obtenerMovimientoComputadora(const char tablero[]) {

    srand(static_cast<unsigned>(time(0)));

    int movimiento;

    do {

        movimiento = rand() % 9;

    } while (tablero[movimiento] != ' ');

    return movimiento;

}



void reiniciarTablero(char tablero[]) {

    for (int i = 0; i < 9; i++) {

        tablero[i] = ' ';

    }

}



void cambiarColor(int color) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}



void limpiarPantalla() {

    system("cls");

}

