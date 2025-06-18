#include "tablero.h"
#include "casillaselec.h"
#include "DATOS_DIBUJO.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool Tablero::turno = 0;

Tablero::Tablero(){
    for (int fila = 0; fila < 8; fila++)
        for (int col = 0; col < 8; col++)
            casillas[fila][col] = nullptr;
}

Tablero& Tablero::operator=(const Tablero& tab)
{

    if (this != &tab)
    {
        // Primero limpia piezas antiguas
        player1.lista_piezas_actuales.limpiar();
        player1.lista_piezas_comidas.limpiar();
        player2.lista_piezas_actuales.limpiar();
        player2.lista_piezas_comidas.limpiar();


        for (int fila = 0; fila < 8; ++fila)
        {
            for (int col = 0; col < 8; ++col)
            {
                delete casillas[fila][col];
                casillas[fila][col] = nullptr;

                if (tab.casillas[fila][col])
                {
                    casillas[fila][col] = tab.casillas[fila][col]->clonar();

                    if (casillas[fila][col]->getColor() == Colorpieza::BLANCO)
                        player1.lista_piezas_actuales.agregar(casillas[fila][col]);
                    else
                        player2.lista_piezas_actuales.agregar(casillas[fila][col]);
                }
            }
        }
        // Copia nombres y turnos
        player1.Nombre = tab.player1.Nombre;
        player2.Nombre = tab.player2.Nombre;
        player1.Turno = tab.player1.Turno;
        player2.Turno = tab.player2.Turno;
        player1.temp = tab.player1.temp;
        player2.temp = tab.player2.temp;
        player1.points = tab.player1.points;
        player2.points = tab.player2.points;
    }
    return *this;
}


Tablero::~Tablero() {
    //std::cout << "Destruyendo pieza en: " << this << endl;
    for (int fila = 0; fila < 8; fila++)
        for (int col = 0; col < 8; col++)
            if (casillas[fila][col] != nullptr && casillas[fila][col])
            {
                delete casillas[fila][col];
                casillas[fila][col] = nullptr;
            }
}

void Tablero::inicializar() {
    for (int fila = 0; fila < 8; fila++)
        for (int col = 0; col < 8; col++)
            casillas[fila][col] = nullptr;

    // Negras derecha (columna 6 y 7)
    casillas[0][7] = new Torre(Colorpieza::NEGRO);
    casillas[1][7] = new Caballo(Colorpieza::NEGRO);
    casillas[2][7] = new Alfil(Colorpieza::NEGRO);
    casillas[3][7] = new Reina(Colorpieza::NEGRO);
    casillas[4][7] = new Rey(Colorpieza::NEGRO);
    casillas[5][7] = new Alfil(Colorpieza::NEGRO);
    casillas[6][7] = new Caballo(Colorpieza::NEGRO);
    casillas[7][7] = new Torre(Colorpieza::NEGRO);
    for (int i = 0; i < 8; i++)
        casillas[i][6] = new Peon(Colorpieza::NEGRO);

    for (int i = 7; i >= 6; i--) //Agregamos las piezas del player 2 a la lista de sus piezas sobre el tablero (Guarda primero la columna de figuras y luego la de peones)
    {
        for (int j = 0; j < 8; j++)
            player2.lista_piezas_actuales.agregar(casillas[j][i]);
    }

    // Blancas izquierda (columna 0 y 1)
    for (int i = 0; i < 8; i++)
        casillas[i][1] = new Peon(Colorpieza::BLANCO);

    casillas[0][0] = new Torre(Colorpieza::BLANCO);
    casillas[1][0] = new Caballo(Colorpieza::BLANCO);
    casillas[2][0] = new Alfil(Colorpieza::BLANCO);
    casillas[3][0] = new Reina(Colorpieza::BLANCO);
    casillas[4][0] = new Rey(Colorpieza::BLANCO);
    casillas[5][0] = new Alfil(Colorpieza::BLANCO);
    casillas[6][0] = new Caballo(Colorpieza::BLANCO);
    casillas[7][0] = new Torre(Colorpieza::BLANCO);

    for (int i = 0; i <= 1; i++) //Agregamos las piezas del player 2 a la lista de sus piezas sobre el tablero (Guarda primero la columna de figuras y luego la de peones)
    {
        for (int j = 0; j < 8; j++)
            player1.lista_piezas_actuales.agregar(casillas[j][i]);
    }
}

void Tablero::mostrar() {
    cout << "  ";
    for (int col = 0; col <= 7; col++) cout << col + 1 << " "; //Imprime los numeros de columnas
    cout << "\n";

    for (int fila = 0; fila <= 7; fila++) {
        cout << char('a' + fila) << " "; //Imprime las letras de las filas
        for (int col = 0; col <= 7; col++) {
            char simbolo = '.';
            Pieza* pieza = casillas[fila][col];
            if (pieza) {
                switch (pieza->getTipo()) {
                case TipoPieza::PEON: simbolo = 'P'; break;
                case TipoPieza::TORRE: simbolo = 'T'; break;
                case TipoPieza::CABALLO: simbolo = 'C'; break;
                case TipoPieza::ALFIL: simbolo = 'A'; break;
                case TipoPieza::REINA: simbolo = 'Q'; break;
                case TipoPieza::REY: simbolo = 'K'; break;
                default:
                    simbolo = '?'; break;
                }
                if (pieza->getColor() == Colorpieza::BLANCO)
                    simbolo = tolower(simbolo);
            }
            cout << simbolo << ' ';
        }
        cout << "\n";
    }
}

bool Tablero::mover(int FilIni, int ColIni, int FilFin, int ColFin, Jugador& player, DATOS_DIBUJO& dat) {

    Pieza* casilla_origen = this->getCasilla(FilIni, ColIni);
    Pieza* casilla_destino = this->getCasilla(FilFin, ColFin);
    Casilla posFin = { FilFin, ColFin };



    if (casilla_origen->movimientoValido(FilIni, ColIni, FilFin, ColFin, *this)) //Comprobamos si el movimiento de la pieza seleccionado es correcto
    {
        dat.pieza_origen = casilla_origen; //Sacamos la casilla de inicio y final pre-gravedad para llevarlo a INFO.CPP para dibujarla 
        dat.pieza_fin_sinGrav = casilla_destino;
        if (casilla_destino != nullptr)
        {
            if (casilla_destino->getTipo() == TipoPieza::REY)
            {
                if (casilla_origen->getColor() == casilla_destino->getColor()) //Para evitar que una pieza se coma a su propio rey (de su mismo color)
                {
                    cout << "La pieza no puede comerse a su propio rey" << endl;
                    return false;
                }

            }
        }

        this->resetCasilla(FilFin, ColFin); //Liberamos la casilla de destino
        this->setCasilla(FilFin, ColFin, casilla_origen); //Aplicamos el movimiento
        dat.pieza_fin_conGrav = getCasilla(FilFin, ColFin);
        this->resetCasilla(FilIni, ColIni); //Liberamos la casilla de origen

        if (aplicarGravedad(*this, posFin, dat.pieza_fin_conGrav))
        {
            
            if (casilla_destino != nullptr)
                player.lista_piezas_comidas.agregar(casilla_destino); //Agregamos la pieza que el jugador se come a su lista de piezas comidas

            return true;
        }


    }
    return false;
}


bool Tablero::aplicarGravedad(Tablero& tab, Casilla destino_sinGravedad, Pieza*& Pieza_final_conGrav) 
{


    for (int columna = 0; columna <= 7; columna++)
    {
        for (int fila = 7; fila >= 0; fila--) {
            if (casillas[fila][columna] != nullptr) 
            {
                int destino = fila; //Destino es un flag que nos ayudará a saber si hay hueco libre debajo de una pieza y almacenar la posición hasta la que puede bajar una pieza

                while (destino + 1 < 8 && casillas[destino + 1][columna] == nullptr) { //Hay espacio debajo de la pieza
                    destino++;
                }
                if (destino != fila) { //Ha cambiado el flag por lo que hay espacio debajo de la pieza

                    casillas[destino][columna] = casillas[fila][columna]; //Movemos la pieza
                    casillas[fila][columna] = nullptr; //Dejamos libre el sitio en el que estaba

                }
                

            }
        }
    }
    return true;


}

Casilla Tablero::buscar_pieza(Pieza* p)
{
    for (int fila = 0; fila <= 7; fila++)
    {
        for (int columna = 0; columna <= 7; columna++)
        {
            if (casillas[fila][columna] == p)
            {
                Casilla encontrado = { fila, columna };
                return encontrado;
            }

        }
    }
    return { -1,-1 };
}

bool Tablero::gestion_jaque(Jugador defensor, Jugador atacante) //Devuelve TRUE - Si hay forma d escapar del JAQUE y FALSE si es JAQUE MATE
{
    int pos_listaRey = 0;
    Casilla casillaRey;
    Casilla piezas_atacantes;
    Casilla piezas_atacantes2;
    Casilla piezas_defensoras;
    int escape_rey = 0;

    //Detectamos la posicion del rey en la lista de piezas sobre el tablero del jugador defensor
    for (int i = 0; i < defensor.lista_piezas_actuales.size(); i++)
        if (defensor.lista_piezas_actuales.lista_piezas[i]->getTipo() == TipoPieza::REY)
            pos_listaRey = i;

    //Primero comprobamos si el rey puede hacer algún movimiento que evite el Jaque
    casillaRey = buscar_pieza(defensor.lista_piezas_actuales.lista_piezas[pos_listaRey]);
    Pieza* rey = getCasilla(casillaRey.row, casillaRey.file);
    for (int fila = 0; fila <= 7; fila++)
    {
        for (int columna = 0; columna <= 7; columna++)
        {
            if (rey->movimientoValido(casillaRey.row, casillaRey.file, fila, columna, *this))
            {
                for (int j = 0; j < atacante.lista_piezas_actuales.size(); j++) //Comprobamos si la posicíón a la que se puede mover está amenazada por otra pieza atacante
                {
                    piezas_atacantes = buscar_pieza(atacante.lista_piezas_actuales.lista_piezas[j]);
                    if (piezas_atacantes.row != -1)
                    {
                        Pieza* atacante1 = getCasilla(piezas_atacantes.row, piezas_atacantes.file);
                        if (atacante1->movimientoValido(piezas_atacantes.row, piezas_atacantes.file, fila, columna, *this)) //Comprobamos si la posicion a la que se puede mover el rey está amenazada
                        {
                            //El rey no se puede mover a esa posición -> Hay que comprobar si podemos cubrir al rey con una pieza
                            for (int m = 0; m < defensor.lista_piezas_actuales.size(); m++)
                            {
                                if (defensor.lista_piezas_actuales.lista_piezas[m]->getTipo() != TipoPieza::REY)
                                {
                                    piezas_defensoras = buscar_pieza(defensor.lista_piezas_actuales.lista_piezas[m]);

                                    if (piezas_defensoras.row != -1)
                                    {
                                        Pieza* defensor = getCasilla(piezas_defensoras.row, piezas_defensoras.file);

                                        for (int f = 0; f <= 7; f++)
                                        {
                                            for (int c = 0; c <= 7; c++)
                                            {
                                                if (defensor->movimientoValido(piezas_defensoras.row, piezas_defensoras.file, f, c, *this))
                                                {
                                                    setCasilla(f, c, defensor);
                                                    for (int k = 0; k < atacante.lista_piezas_actuales.size(); k++) //Comprobamos si la posicíón a la que se puede mover está amenazada por otra pieza atacante
                                                    {
                                                        piezas_atacantes2 = buscar_pieza(atacante.lista_piezas_actuales.lista_piezas[k]);
                                                        if (piezas_atacantes2.row != -1)
                                                        {
                                                            Pieza* atacante2 = getCasilla(piezas_atacantes2.row, piezas_atacantes2.file);
                                                            if (atacante2->movimientoValido(piezas_atacantes2.row, piezas_atacantes2.file, casillaRey.row, casillaRey.file, *this)) //Comprobamos si la pieza defensora consigue bloquear al rey
                                                            {
                                                                resetCasilla(f, c); //El defensor no ha podido proteger al rey
                                                                escape_rey = 0;
                                                            }
                                                            else
                                                            {
                                                                resetCasilla(f, c);
                                                                return true; //El defensor puede proteger al rey
                                                            }
                                                        }

                                                    }
                                                }


                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                            escape_rey = 1; //No está amenazada y se puede mover a ella
                    }
                }
                if (escape_rey == 1) //El rey ha podido moverse a una casilla donde no está amenazado
                    return true;
                else
                    return false; //El rey no ha podido salir del JAQUE, por tanto, JAQUE MATE
            }
        }
    }
}

bool Tablero::comprobacion_jaque(Jugador turno_activo, Jugador turno_inactivo)
{
    int pos_listaRey = 0;
    Casilla casillaRey;
    Casilla piezas_atacantes;
    Casilla piezas_defensoras;
    int escape_rey = 0;

    //Detectamos la posicion del rey sobre el tablero del jugador defensor
    for (int i = 0; i < turno_inactivo.lista_piezas_actuales.size(); i++)
        if (turno_inactivo.lista_piezas_actuales.lista_piezas[i]->getTipo() == TipoPieza::REY)
            pos_listaRey = i;

    casillaRey = buscar_pieza(turno_inactivo.lista_piezas_actuales.lista_piezas[pos_listaRey]);
    Pieza* rey = getCasilla(casillaRey.row, casillaRey.file);

    for (int i = 0; i < turno_activo.lista_piezas_actuales.size(); i++)
    {
        piezas_atacantes = buscar_pieza(turno_activo.lista_piezas_actuales.lista_piezas[i]);

        if (piezas_atacantes.row == -1 || piezas_atacantes.file == -1) {
            cout << "ERROR: Pieza atacante no encontrada. Saltando...\n";
            continue; // Evita continuar con datos inválidos
        }

        Pieza* atacante1 = getCasilla(piezas_atacantes.row, piezas_atacantes.file);

        if (atacante1 == nullptr) {
            cout << "ERROR: Puntero nulo en atacante1. Saltando...\n";
            continue;
        }

        if (atacante1->getTipo() != TipoPieza::VACIA)
        {
            if (atacante1->movimientoValido(
                piezas_atacantes.row, piezas_atacantes.file,
                casillaRey.row, casillaRey.file, *this)) {

                cout << "JAQUE AL REY" << endl;
                return true;
            }
        }
    }
    return false;

}

void Tablero::comp_coronacion(Casilla cas_final_p)
{
    int aux;//Para controlar que pieza quiere
    TipoPieza p;
    int columna_fin = cas_final_p.file;
    int fila_fin = cas_final_p.row;
    p = casillas[fila_fin][columna_fin]->getTipo();
    Colorpieza color = casillas[fila_fin][columna_fin]->getColor();


    if (int(p) == 1 && columna_fin == 7 && color == Colorpieza::BLANCO)
    {

        std::cout << "Escoge la pieza que quieres obtener: TORRE-2, CABALLO-3, ALFIL-4, REINA-6: ";
        std::cin >> aux;
        while (aux != 2 && aux != 3 && aux != 4 && aux != 6)
        {
            std::cout << "\nNumero incorrecto, por favor:" << endl;
            std::cout << "Escoge la pieza que quieres obtener: TORRE-2, CABALLO-3, ALFIL-4, REINA-6: ";
            std::cin >> aux;
        }

        switch (aux) {
        case 2:
            player1.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Torre(color);
            player1.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        case 3:
            player1.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Caballo(color);
            player1.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        case 4:
            player1.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Alfil(color);
            player1.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        case 6:
            player1.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Reina(color);
            player1.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        default:
            player1.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Reina(color);
            player1.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        }
    }

    if (int(p) == 1 && columna_fin == 0 && color == Colorpieza::NEGRO)
    {

        std::cout << "Escoge la pieza que quieres obtener: TORRE-2, CABALLO-3, ALFIL-4, REINA-6: ";
        std::cin >> aux;

        switch (aux) {
        case 2:
            player2.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Torre(color);
            player2.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        case 3:
            player2.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Caballo(color);
            player2.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        case 4:
            player2.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Alfil(color);
            player2.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        case 6:
            player2.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Reina(color);
            player2.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        default:
            player2.lista_piezas_actuales.eliminar(casillas[fila_fin][columna_fin]);
            casillas[fila_fin][columna_fin] = nullptr;
            casillas[fila_fin][columna_fin] = new Reina(color);
            player2.lista_piezas_actuales.agregar(casillas[fila_fin][columna_fin]);
            break;
        }
    }


}

bool Tablero::gestion_turnos(bool& estado_JAQUE, DATOS_DIBUJO& dat, char tecla)
{
    string entrada;
    bool jaque = estado_JAQUE;
    char key_seleccion = tecla;
    Tablero backup;
    backup = *this; //Copia del tablero al inicio del turno por si es necesario volver para atrás
    

    if (player1.Turno) //TURNO PLAYER 1
    {
        turno = 1;
        cout << "Turno de " << player1.Nombre << ":" << endl;


        if (!jaque)
        {
            if (player1.seleccion_casilla(*this, dat,key_seleccion)) //TRUE si el movimiento se ha realizado correctamente
            {

                if (!comprobacion_jaque(player1, player2)) //Comprobamos si player1 hace JAQUE con su movimiento a player 2
                {
                    if (dat.pieza_fin_conGrav != nullptr)
                      comp_coronacion(buscar_pieza(dat.pieza_fin_conGrav));
                  
                    player1.actualizar_listas(player2); //Actualizamos las listas por si un jugador ha comido piezas al otro y hay que eliminarlas de su lista de piezas sobre el tablero
                    player2.actualizar_listas(player1);
                    
                    player1.Turno = false;
                    player2.Turno = true;
                    

                }
                else //Hay JAQUE al rey
                {
                    //comp_coronacion(buscar_pieza(dat.pieza_fin_conGrav));
                    player1.actualizar_listas(player2); //Actualizamos las listas por si un jugador ha comido piezas al otro y hay que eliminarlas de su lista de piezas sobre el tablero
                    player2.actualizar_listas(player1);

                    jaque = true;
                    player1.Turno = false;
                    player2.Turno = true;
                 
                }
            }
        }

        else //Player 1 está en JAQUE
        {
            if (gestion_jaque(player1, player2)) //Comprueba si el rey tiene opciones de salvarse
            {
                if (player1.seleccion_casilla(*this, dat,key_seleccion))
                {
                    if (!comprobacion_jaque(player2, player1)) //Comprobamos si ha salido del JAQUE
                    {
                        //comp_coronacion(buscar_pieza(dat.pieza_fin_conGrav));
                        player1.actualizar_listas(player2); //Actualizamos las listas por si un jugador ha comido piezas al otro y hay que eliminarlas de su lista de piezas sobre el tablero
                        player2.actualizar_listas(player1);

                        player1.Turno = false;
                        player2.Turno = true;
                        jaque = false; //Ha salido del JAQUE
                      

                    }
                    else
                    {
                        //No actualizamos listas porque se ha cancelado el movimiento seleccionado porque el rey sigue en jaque
                        cout << "EL REY SIGUE ESTANDO EN JAQUE, HAZ OTRO MOVIMIENTO" << endl;
                        *this = backup; //No vale el movimiento, retornamos al estado anterior del tablero
                        player1.Turno = true; //Repetimos su turno
                        player2.Turno = false;

                    }
                }


            }
            else
                return false; //JAQUE MATE - TERMINA LA PARTIDA


        }

        estado_JAQUE = jaque;
        return true; //Termina el turno

    }

    else //TURNO PLAYER 2
    {
        
        turno = 0;
        cout << "Turno de " << player2.Nombre << ":" << endl;
        if (!jaque)
        {
            if (player2.seleccion_casilla(*this, dat,key_seleccion))
            {
                if (!comprobacion_jaque(player2, player1))
                {
                    if (dat.pieza_fin_conGrav != nullptr)
                        comp_coronacion(buscar_pieza(dat.pieza_fin_conGrav));

                    player1.actualizar_listas(player2); //Actualizamos las listas por si un jugador ha comido piezas al otro y hay que eliminarlas de su lista de piezas sobre el tablero
                    player2.actualizar_listas(player1);

                    player2.Turno = false;
                    player1.Turno = true;
                 
                }
                else
                {
                    //comp_coronacion(buscar_pieza(dat.pieza_fin_conGrav));
                    player1.actualizar_listas(player2); //Actualizamos las listas por si un jugador ha comido piezas al otro y hay que eliminarlas de su lista de piezas sobre el tablero
                    player2.actualizar_listas(player1);

                    jaque = true; //Hay JAQUE del player 2 al player 1
                    player1.Turno = true;
                    player2.Turno = false;
                    
                }
            }
        }
        else
        {
            if (gestion_jaque(player2, player1))
            {

                if (player2.seleccion_casilla(*this, dat,key_seleccion))
                {
                    if (!comprobacion_jaque(player1, player2))
                    {
                        //comp_coronacion(buscar_pieza(dat.pieza_fin_conGrav));
                        player1.actualizar_listas(player2); //Actualizamos las listas por si un jugador ha comido piezas al otro y hay que eliminarlas de su lista de piezas sobre el tablero
                        player2.actualizar_listas(player1);

                        player1.Turno = true;
                        player2.Turno = false;
                        jaque = false;
                    }
                    else
                    {
                        //No actualizamos listas porque se ha cancelado el movimiento seleccionado porque el rey sigue en jaque
                        cout << "EL REY SIGUE ESTANDO EN JAQUE, HAZ OTRO MOVIMIENTO" << endl;
                        *this = backup;
                        player1.Turno = false;
                        player2.Turno = true;
                        
                    }

                }


            }
            else
                return false; //JAQUE MATE - TERMINA LA PARTIDA

        }

        estado_JAQUE = jaque;
        return true; //Termina el turno
    }


}


bool Tablero::guardarPartida(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) return false;

    archivo << "JUGADOR1: " << player1.Nombre << "\n";
    archivo << "JUGADOR2: " << player2.Nombre << "\n";
    archivo << "TURNO: " << (player1.Turno ? 1 : 2) << "\n";
    archivo << "TABLERO:\n";

    for (int fila = 0; fila < 8; fila++) {
        for (int col = 0; col < 8; col++) {
            Pieza* pieza = casillas[fila][col];
            if (pieza) {
                archivo << static_cast<int>(pieza->getTipo()) << " "
                    << static_cast<int>(pieza->getColor()) << " "
                    << fila << " " << col << "\n";
            }
        }
    }

    archivo.close();
    return true;
}

bool Tablero::cargarPartida(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return false;

    string linea;
    int turno;
    getline(archivo, linea); player1.Nombre = linea.substr(10);
    getline(archivo, linea); player2.Nombre = linea.substr(10);
    getline(archivo, linea); turno = stoi(linea.substr(7));
    player1.Turno = (turno == 1);
    player2.Turno = !player1.Turno;

    // Limpiar tablero actual
    for (int f = 0; f < 8; ++f)
        for (int c = 0; c < 8; ++c)
            casillas[f][c] = nullptr;

    player1.lista_piezas_actuales = ListaPiezas();
    player2.lista_piezas_actuales = ListaPiezas();

    getline(archivo, linea); // "TABLERO:"
    int tipo, color, fila, col;

    while (archivo >> tipo >> color >> fila >> col) {
        Pieza* nueva = nullptr;
        Colorpieza colP = static_cast<Colorpieza>(color);

        switch (static_cast<TipoPieza>(tipo)) {
        case TipoPieza::PEON: nueva = new Peon(colP); break;
        case TipoPieza::TORRE: nueva = new Torre(colP); break;
        case TipoPieza::CABALLO: nueva = new Caballo(colP); break;
        case TipoPieza::ALFIL: nueva = new Alfil(colP); break;
        case TipoPieza::REINA: nueva = new Reina(colP); break;
        case TipoPieza::REY: nueva = new Rey(colP); break;
        default: break;
        }

        if (nueva) {
            casillas[fila][col] = nueva;
            if (colP == Colorpieza::BLANCO)
                player1.lista_piezas_actuales.agregar(nueva);
            else
                player2.lista_piezas_actuales.agregar(nueva);
        }
    }

    return true;
}

void Tablero::mostrarConCursor(int fila_cursor, int col_cursor) {
    std::cout << "  ";
    for (int col = 0; col <= 7; col++) std::cout << col + 1 << " ";
    std::cout << "\n";

    for (int fila = 0; fila <= 7; fila++) {
        std::cout << char('a' + fila) << " ";
        for (int col = 0; col <= 7; col++) {
            if (fila == fila_cursor && col == col_cursor) {
                std::cout << "[";
            }
            else {
                std::cout << " ";
            }

            char simbolo = '.';
            Pieza* pieza = casillas[fila][col];
            if (pieza) {
                switch (pieza->getTipo()) {
                case TipoPieza::PEON: simbolo = 'P'; break;
                case TipoPieza::TORRE: simbolo = 'T'; break;
                case TipoPieza::CABALLO: simbolo = 'C'; break;
                case TipoPieza::ALFIL: simbolo = 'A'; break;
                case TipoPieza::REINA: simbolo = 'Q'; break;
                case TipoPieza::REY: simbolo = 'K'; break;
                default: simbolo = '?'; break;
                }
                if (pieza->getColor() == Colorpieza::BLANCO)
                    simbolo = tolower(simbolo);
            }
            std::cout << simbolo;

            if (fila == fila_cursor && col == col_cursor) {
                std::cout << "]";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}


