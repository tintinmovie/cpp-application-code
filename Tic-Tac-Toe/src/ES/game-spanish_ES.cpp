/*
________________________________________
|                                       |
|       game-spanish_ES.cpp                        |
|                                        \
|       Google-code-in (2k17-18)          \
|                                          \
|                                           \
|       Juego - Tic-Tac-Toe                   |
|                                            |
`---------@@@@@-------------------@@@--------'
*/



#include "strings-spanish_ES.cpp"
#include <iostream>
using namespace std;



int is_winner(char );
void banner_ttt();
int authenticated_index(int );
void show_status_ttt();
void tic_tac_toe();



// Array que guarda el '0' o 'X' en las posiciones introducidas por los jugadores
//
char a[9] = {'T','T','T','T','T','T','T','T','T'};




int main()
{
	// llama al bloque principal para el juego Tic-Tac-Toe
	tic_tac_toe();
}



// Bloque principal para el juego Tic-Tac-Toe
// El juego empieza desde aquí, juego por turnos
void tic_tac_toe()
{
	int flag = 0, turn_counter = 1;
	int zero, cross;
	int continue_p2 = 0;


	banner_ttt();



		// Pide entrada de usuario hasta que uno de los 2 jugadores gana
		while(1)
		{

			// Verifica si el jugador2 no presionó la tecla continuar,
			// Si no lo hizo, es el turno de jugador1
			//
			if ( continue_p2 != 1 )
			{
				cout<<"Jugador1 -> ";
				// El usuario ingresa la posición que además se utiliza como índice para almacenar '0' en dicha posición del array
				cin>>zero;


					// Verifica si el índice ingresado por el usuario es válido o no
					if (( authenticated_index(zero-1)) )
					{
						++turn_counter;
						a[zero-1] = '0';
						show_status_ttt();

							if (turn_counter > 4 && is_winner('0'))
							{
								cout<<"Felicidades!!\n";
								cout<<"Jugador 1 gana !\n";
								exit(0);
							}
					}

					else
						continue;

			}



			cout<<"Jugador2 -> ";
			cin>>cross;

				// Verifica si el índice ingresado por el usuario es válido o no
				if (authenticated_index(cross-1))
				{

					++turn_counter;
					a[cross-1] = 'X';
					show_status_ttt();
					continue_p2 = 0;

						if (turn_counter > 4  && is_winner('X'))
						{
							cout<<"Felicidades!!\n";
							cout<<"Jugador 2 gana !\n";
							exit(0);
						}
				}

				// Si el índice ingresado por el usuario no es válido
				// Continua dentro del bucle de manera que Jugador2 sigue con su turno
				else
				{
					// Configurando un indicador 'continue_p2' para señalar que
					// Jugador2 tiene la orden de continuar y que
					// el turno sigue siendo del jugador2 y no del Jugador1
					continue_p2 = 1;
					continue;
				}

		}

}



// Devuelve un numero distinto de cero si el jugador llamando la función gana
// y retorna 0 si el jugador llamando la función no ganó aún.
//
int is_winner(char ch)
{
	// El codigo va aquí


}



// Verifica si
// 1. La 'posicion' ingresada por el usuario no fue
// 	  indroducida por uno de los dos usuarios anteriormente.
// 2. La 'posicion' no esta fuera de rango del
//    tablero de juego.
// Devuelve 1 si la posicion es valida, de otra manera 0.
//
int authenticated_index(int index)
{
	// El codigo va aquí


}



// Muestra el estado actual del juego
// Es llamada cada vez que un usuario tiene su turno.
void show_status_ttt()
{

	cout<<"\n";

	for( int i=0 ; i<9 ; ++i )
	{

		if (i != 0 && i%3 == 0 )
		{
			cout<<"\n";
			cout<<"___|___|___\n";
		}

		cout<<" ";

		if ( a[i] == '0' || a[i] == 'X' )
			{
				cout<<(char )a[i]<<" ";
				if (i != 2 && i != 5 && i !=8)
					cout<<"|";

			}

			else
			{
				cout<<"  ";
				if (i != 2 && i !=5 && i != 8)
					cout<<"|";
			}
	}

	cout<<"\n   |   |   \n";

	cout<<"\n";
}





