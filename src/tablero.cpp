#include "tablero.h"
#include "cstdio"
#include <ctime>
#include <iostream>

Tablero::Tablero() {
    // Inicializa todas las casillas a nullptr
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            casillas[y][x] = nullptr;
        }
    }
}

Tablero::~Tablero() {
    // Elimina todas las piezas en el tablero
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            delete casillas[y][x];
        }
    }
}

void Tablero::inicializar() {
    // Inicializar las piezas negras (fila 0 y 1)
    casillas[0][0] = new Torre(Colorpieza::NEGRO);
    casillas[0][1] = new Caballo(Colorpieza::NEGRO);
    casillas[0][2] = new Alfil(Colorpieza::NEGRO);
    casillas[0][3] = new Reina(Colorpieza::NEGRO);
    casillas[0][4] = new Rey(Colorpieza::NEGRO);
    casillas[0][5] = new Alfil(Colorpieza::NEGRO);
    casillas[0][6] = new Caballo(Colorpieza::NEGRO);
    casillas[0][7] = new Torre(Colorpieza::NEGRO);

    for (int i = 0; i < 8; i++) {
        casillas[1][i] = new Peon(Colorpieza::NEGRO);  // Peones negros
    }

    // Inicializar las piezas blancas (fila 6 y 7)
    casillas[7][0] = new Torre(Colorpieza::BLANCO);
    casillas[7][1] = new Caballo(Colorpieza::BLANCO);
    casillas[7][2] = new Alfil(Colorpieza::BLANCO);
    casillas[7][3] = new Reina(Colorpieza::BLANCO);
    casillas[7][4] = new Rey(Colorpieza::BLANCO);
    casillas[7][5] = new Alfil(Colorpieza::BLANCO);
    casillas[7][6] = new Caballo(Colorpieza::BLANCO);
    casillas[7][7] = new Torre(Colorpieza::BLANCO);

    for (int i = 0; i < 8; i++) {
        casillas[6][i] = new Peon(Colorpieza::BLANCO);  // Peones blancos
    }
}

void Tablero::mostrar() {
    for (int y = 7; y >= 0; y--) {
        std::cout << y + 1 << " ";
        for (int x = 0; x < 8; x++) {
            char simbolo = '.';
            if (casillas[y][x]) {
                switch (casillas[y][x]->getTipo()) {
                case TipoPieza::PEON: simbolo = 'P'; break;
                case TipoPieza::TORRE: simbolo = 'T'; break;
                case TipoPieza::CABALLO: simbolo = 'C'; break;
                case TipoPieza::ALFIL: simbolo = 'A'; break;
                case TipoPieza::REINA: simbolo = 'Q'; break;
                case TipoPieza::REY: simbolo = 'K'; break;
                default: simbolo = '?'; break;
                }

                if (casillas[y][x]->getColor() == Colorpieza::NEGRO)
                    simbolo = tolower(simbolo);
            }
            std::cout << simbolo << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "  a b c d e f g h\n";
}

bool Tablero::mover(int xIni, int yIni, int xFin, int yFin) {
    // Verifica si la casilla de inicio está ocupada por una pieza
    if (!casillas[yIni][xIni]) return false;

    Pieza* pieza = casillas[yIni][xIni];

    // Verifica si el movimiento es válido para esa pieza
    if (pieza->movimientoValido(xIni, yIni, xFin, yFin, *this)) {
        // Si el movimiento es válido, realizamos la captura (si corresponde)
        delete casillas[yFin][xFin];  // Se come la pieza que estaba en la casilla destino
        casillas[yFin][xFin] = pieza; // Movemos la pieza a la nueva casilla
        casillas[yIni][xIni] = nullptr; // Limpiamos la casilla de origen

        aplicarGravedad(xFin); // Aplicar la gravedad en la columna de destino
        return true;
    }

    return false;
}

void Tablero::aplicarGravedad(int columna) {
    // Aplica la gravedad en la columna especificada
    for (int fila = 6; fila >= 0; fila--) {
        if (casillas[fila][columna] != nullptr) {
            int destino = fila;
            while (destino + 1 < 8 && casillas[destino + 1][columna] == nullptr) {
                destino++;  // Desciende la pieza
            }

            if (destino != fila) {
                // Mueve la pieza hacia abajo hasta la casilla vacía
                casillas[destino][columna] = casillas[fila][columna];
                casillas[fila][columna] = nullptr;
            }
        }
    }
}

bool Tablero::com_dentro_tablero(int xFin, int yFin)
{
    if (xFin > 7 || yFin > 7)
    {
        return false;
    }
    else 
    {
        return true;
    } 
}

void Tablero::comp_coronacion(int xFin, int yFin)
{
    int aux;//Para controlar que pieza quiere
    TipoPieza p;
    p = casillas[yFin][xFin]->getTipo();
    
    if (int(p) == 1 && yFin == 7)
    {
        Colorpieza color = casillas[yFin][xFin]->getColor();

        std::cout << "Escoge la pieza que quieres obtener: TORRE-2, CABALLO-3, ALFIL-4, REINA-6: ";
        std::cin >> aux;

        switch (aux) {
        case 2:
          delete casillas[yFin][xFin];
          casillas[yFin][xFin] = new Torre(color);
          break;
        case 3:
           delete casillas[yFin][xFin];
           casillas[yFin][xFin] = new Caballo(color);
           break;
        case 4:
           delete casillas[yFin][xFin];
           casillas[yFin][xFin] = new Alfil(color);
           break;
        case 6:
           delete casillas[yFin][xFin];
           casillas[yFin][xFin] = new Reina(color);
           break;
        default:
           delete casillas[yFin][xFin];
           casillas[yFin][xFin] = new Reina(color);
           break;
        }
    }
}

int Tablero::generador_de_movimientos(Tablero& t)
{
    int numero = std::rand() % 10 + 1;
    bool aux;
    
    
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            TipoPieza p = casillas[i][j]->getTipo();
            Colorpieza color = casillas[i][j]->getColor();
            //xFin = i;
            //yFin = j;

            if ((int(p)==1 || int(p) == 2|| int(p) == 3|| int(p) == 4|| int(p) == 5|| int(p) == 6) && color == Colorpieza::NEGRO)
            {
                for (int c = 0; c <= 7; c++)
                {
                    for (int d = 0; d <= 7; d++)
                    {
                        aux = casillas[i][j]->movimientoValido(i, j, c, d, t);
                        if (aux == true)
                        {
                            casillas[c][d] = casillas[i][j];
                            delete casillas[i][j];
                            casillas[i][j] = nullptr;
                            return 0;
                        }
                    }
                }  
            }
        }
    }
}

bool Tablero::comp_jaque(int xFin, int yFin, Tablero& t)
{
    int pos_rey_c1, pos_rey_c2;
    //Para saber el color de la pieza que acaba de realizar un movimiento
    Colorpieza color_pieza_movida = casillas[yFin][xFin]->getColor();
    //Recorro el tablero para encontrar el rey del color igual al de la pieza movida en la jugada actual

    for (int i = 0; i <= 7; i++){
        for (int j = 0; j <= 7; j++) {
            
            TipoPieza t_comp_rey = casillas[i][j]->getTipo();
            Colorpieza c_comp_rey = casillas[i][j]->getColor();

            if (int(t_comp_rey) == 5 && c_comp_rey != color_pieza_movida)
            {
                pos_rey_c1 = i;
                pos_rey_c2 = j;
                
            }
        }
    }

    //Recorro el tableco para ubicar piezas del color contrario
    for (int c = 0; c <= 7; c++) {
        for (int d = 0; d <= 7; d++) {

            TipoPieza t_pieza_a_comprobar = casillas[c][d]->getTipo();
            Colorpieza c_pieza_a_comprobar = casillas[c][d]->getColor();

            if ((int(t_pieza_a_comprobar) == 1 || int(t_pieza_a_comprobar) == 2 || int(t_pieza_a_comprobar) == 3 ||
                int(t_pieza_a_comprobar) == 4 || int(t_pieza_a_comprobar) == 5 || int(t_pieza_a_comprobar) == 6) &&
                c_pieza_a_comprobar == color_pieza_movida)
            {
                bool aux;
                //Una vez encontrada la pieza compruebo sus movimientos para buscar si hay alguno que acabe en la casilla 
                // del rey del color de la pieza movida

                aux = casillas[c][d]->movimientoValido(c, d, pos_rey_c1, pos_rey_c2, t);
                if (aux == true)
                    return true;
            }
        }
    }

    return false;
}

bool Tablero::comp_jaque_mate(int xFin, int yFin, Tablero& t)
{
    //Primero comprobamos que el rey está en jaque
    bool jaque;
    int atacantes;
    int pos_rey_x, pos_rey_y, pos_atacante_x, pos_atacante_y;
    Colorpieza color_pieza_movida = casillas[xFin][yFin]->getColor();
    
    


    jaque = t.comp_jaque(xFin, yFin, t);
    bool c_atacada1, existe_p_cont1, c_atacada2, existe_p_cont2, c_atacada3, existe_p_cont3,
        c_atacada4, existe_p_cont4, c_atacada5, existe_p_cont5, c_atacada6, existe_p_cont6,
        c_atacada7, existe_p_cont7, c_atacada8, existe_p_cont8;

    if (jaque == true)
    {
        //En caso de que halla jaque comprobamos las posiciones que el rey tiene alrededor
        // Utilizo el valor de 2 para aquellas casillas ocupadas por otras piezas o aquellas que queden fuera del tablero
        //Casos de casilla que rodean al rey: (i++),(i--),(j++),(j--),(i++j++),(i++j--),(i--,j++),(i--j--)
        Pieza* cas_rey = t.buscar_rey(xFin, yFin, pos_rey_x, pos_rey_y);

        int pos_1_x = pos_rey_x + 1;
        int pos_1_y = pos_rey_y;
        if ((pos_1_x <= 7) && (pos_1_y <= 7) && (casillas[pos_1_x][pos_1_y] == nullptr))
        {
            c_atacada1 = t.conocer_casilla_atacada(color_pieza_movida, t, pos_1_x, pos_1_y);
            existe_p_cont1 = t.pieza_mismo_color_cerca_rey(color_pieza_movida, t, pos_1_x, pos_1_y);
        }
        else {
            c_atacada1 = true;
        }
       

        int pos_2_x = pos_rey_x - 1;
        int pos_2_y = pos_rey_y;
        if ((pos_2_x <= 7) && (pos_2_y <= 7) && (casillas[pos_2_x][pos_2_y] == nullptr))
        {
            c_atacada2 = t.conocer_casilla_atacada(color_pieza_movida, t, pos_2_x, pos_2_y);
            existe_p_cont2 = t.pieza_mismo_color_cerca_rey(color_pieza_movida, t, pos_2_x, pos_2_y);
        }
        else {
            c_atacada2 = true;
        }
       

        int pos_3_x = pos_rey_x;
        int pos_3_y = pos_rey_y + 1;
        if ((pos_3_x <= 7) && (pos_3_y <= 7) && (casillas[pos_3_x][pos_3_y] == nullptr))
        {
            c_atacada3 = t.conocer_casilla_atacada(color_pieza_movida, t, pos_3_x, pos_3_y);
            existe_p_cont3 = t.pieza_mismo_color_cerca_rey(color_pieza_movida, t, pos_3_x, pos_3_y);
        }
        else {
            c_atacada3 = true;
        }
        

        int pos_4_x = pos_rey_x;
        int pos_4_y = pos_rey_y - 1;
        if ((pos_4_x <= 7) && (pos_4_y <= 7) && (casillas[pos_4_x][pos_4_y] == nullptr))
        {
            c_atacada4 = t.conocer_casilla_atacada(color_pieza_movida, t, pos_4_x, pos_4_y);
            existe_p_cont4 = t.pieza_mismo_color_cerca_rey(color_pieza_movida, t, pos_4_x, pos_4_y);
        }
        else {
            c_atacada4 = true;
        }
       

        int pos_5_x = pos_rey_x + 1;
        int pos_5_y = pos_rey_y + 1;
        if ((pos_5_x <= 7) && (pos_5_y <= 7) && (casillas[pos_5_x][pos_5_y] == nullptr))
        {
            c_atacada5 = t.conocer_casilla_atacada(color_pieza_movida, t, pos_5_x, pos_5_y);
            existe_p_cont5 = t.pieza_mismo_color_cerca_rey(color_pieza_movida, t, pos_5_x, pos_5_y);
        }
        else {
            c_atacada5 = true;
        }
        

        int pos_6_x = pos_rey_x + 1;
        int pos_6_y = pos_rey_y - 1;
        if ((pos_6_x <= 7) && (pos_6_y <= 7) && (casillas[pos_6_x][pos_6_y] == nullptr))
        {
            c_atacada6 = t.conocer_casilla_atacada(color_pieza_movida, t, pos_6_x, pos_6_y);
            existe_p_cont6 = t.pieza_mismo_color_cerca_rey(color_pieza_movida, t, pos_6_x, pos_6_y);
        }
        else {
            c_atacada6 = true;
        }
       

        int pos_7_x = pos_rey_x - 1;
        int pos_7_y = pos_rey_y - 1;
        if ((pos_7_x <= 7) && (pos_7_y <= 7) && (casillas[pos_7_x][pos_7_y] == nullptr))
        {
            c_atacada7 = t.conocer_casilla_atacada(color_pieza_movida, t, pos_7_x, pos_7_y);
            existe_p_cont7 = t.pieza_mismo_color_cerca_rey(color_pieza_movida, t, pos_7_x, pos_7_y);
        }
        else {
            c_atacada7 = true;
        }
      

        int pos_8_x = pos_rey_x - 1;
        int pos_8_y = pos_rey_y + 1;
        if ((pos_8_x <= 7) && (pos_8_y <= 7) && (casillas[pos_8_x][pos_8_y] == nullptr))
        {
            c_atacada8 = t.conocer_casilla_atacada(color_pieza_movida, t, pos_8_x, pos_8_y);
            existe_p_cont8 = t.pieza_mismo_color_cerca_rey(color_pieza_movida, t, pos_8_x, pos_8_y);
        }
        else {
            c_atacada8 = true;
        }
        

        if ((c_atacada1 == true || existe_p_cont1 == true) && (c_atacada2 == true || existe_p_cont2 == true) 
            && (c_atacada3 == true || existe_p_cont3 == true) && (c_atacada4 == true || existe_p_cont4 == true) &&
            (c_atacada5 == true || existe_p_cont5 == true) && (c_atacada6 == true || existe_p_cont6 == true)
            && (c_atacada7 == true || existe_p_cont7 == true) && (c_atacada8 == true || existe_p_cont8 == true))
        {
                
            atacantes = t.numero_atacantes(color_pieza_movida, xFin, yFin, t);
                
            if (atacantes > 1)
                return true;
            if (atacantes == 1)
            {
                //Compruebo que alguna pieza se puede comer a la pieza que da el jaque
                int ret = t.posicion_atacante(pos_atacante_x, pos_atacante_y, color_pieza_movida, xFin, yFin, t);
                for (int i = 0; i <= 7; i++) {
                    for (int j = 0; j <= 7; j++) {

                        TipoPieza Pieza_a_comp = casillas[i][j]->getTipo();
                        Colorpieza Color_a_comp = casillas[i][j]->getColor();

                        if ((int(Pieza_a_comp) == 1 || int(Pieza_a_comp) == 2 || int(Pieza_a_comp) == 3 ||
                            int(Pieza_a_comp) == 4 || int(Pieza_a_comp) == 5 || int(Pieza_a_comp) == 6) &&
                            Color_a_comp != color_pieza_movida)
                        {
                            bool puede_comer_at = casillas[i][j]->movimientoValido(i, j, pos_atacante_x, pos_atacante_y, t);

                            if (puede_comer_at == true)
                                return false;
                        }
                    }
                }

                //Compruebo todas las jugadas del contrario para comprobar el último caso: una pieza puede bloquear el jaque
                for (int i = 0; i <= 7; i++) {
                    for (int j = 0; j <= 7; j++) {

                        TipoPieza Pieza_a_comp = casillas[i][j]->getTipo();
                        Colorpieza Color_a_comp = casillas[i][j]->getColor();

                        if ((int(Pieza_a_comp) == 1 || int(Pieza_a_comp) == 2 || int(Pieza_a_comp) == 3 ||
                            int(Pieza_a_comp) == 4 || int(Pieza_a_comp) == 5 || int(Pieza_a_comp) == 6) &&
                            Color_a_comp != color_pieza_movida)
                        {
                            
                            TipoPieza Pieza_a_mover = casillas[i][j]->getTipo();
                            Colorpieza Color_p_a_mover = casillas[i][j]->getColor();
                            for (int c = 0; c <= 7; c++) {
                                for (int d = 0; d <= 7; d++) {

                                    bool aux = casillas[i][j]->movimientoValido(i, j, c, d, t);
                                    if (aux == true)
                                    {
                                        delete casillas[i][j];
                                        casillas[i][j] = nullptr;
                                        casillas[c][d] = crearPieza(Pieza_a_mover, Color_p_a_mover);  
                                    }
                                    
                                    bool comp_jaque = t.comp_jaque(xFin, yFin, t);

                                    delete casillas[c][d];
                                    casillas[c][d] = nullptr;
                                    casillas[i][j] = crearPieza(Pieza_a_comp, Color_a_comp);

                                    if (comp_jaque == false)
                                        return false;
                                    
                                }
                            }

                        }
                    }
                }

                return true;
                
            }
           
        }
        return false;        
    }
    return false;
}

//Funciones auxiliares para el jaque mate
Pieza* Tablero::buscar_rey(int xFin, int yFin, int& pos_rey_x, int& pos_rey_y)
{
    //Color de la pieza movida en el turno
    Colorpieza color_pieza_actual = casillas[yFin][xFin]->getColor();

    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {

            TipoPieza t_comp_rey = casillas[i][j]->getTipo();
            Colorpieza c_comp_rey = casillas[i][j]->getColor();

            if (int(t_comp_rey) == 5 && c_comp_rey != color_pieza_actual){
                
                pos_rey_x = i;
                pos_rey_y = j;
                return casillas[i][j];
            }
        }
    }
}


bool Tablero::conocer_casilla_atacada(Colorpieza color, Tablero& t, int& cas_atacada_x, int& cas_atacada_y)
{
    
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {

            Colorpieza color_a_comp = casillas[i][j]->getColor();
            TipoPieza tipo_p_a_comp = casillas[i][j]->getTipo();

            if ((int(tipo_p_a_comp) == 1 || int(tipo_p_a_comp) == 2 || int(tipo_p_a_comp) == 3 ||
                int(tipo_p_a_comp) == 4 || int(tipo_p_a_comp) == 5 || int(tipo_p_a_comp) == 6) &&
                color_a_comp == color)
            {
                bool aux = casillas[i][j]->movimientoValido(i, j, cas_atacada_x, cas_atacada_y, t);
                
                if (aux == true)
                    return true;
                
            }
        }
    }
    return false;
}

bool Tablero::pieza_mismo_color_cerca_rey(Colorpieza color, Tablero& t, int& cas_atacada_x, int& cas_atacada_y)
{
    Colorpieza color_cas_atacada = casillas[cas_atacada_x][cas_atacada_y]->getColor();
    TipoPieza tipo_cas_atacada = casillas[cas_atacada_x][cas_atacada_y]->getTipo();

    if ((int(tipo_cas_atacada) == 1 || int(tipo_cas_atacada) == 2 || int(tipo_cas_atacada) == 3 ||
        int(tipo_cas_atacada) == 4 || int(tipo_cas_atacada) == 6) &&
        color_cas_atacada != color)
    {
        return true;
    }

    return false;
}

int Tablero::numero_atacantes(Colorpieza c, int xFin, int yFin, Tablero& t)
{
    Pieza* pos_rey;
    int pos_rey_x, pos_rey_y, num_atacantes = 0;

    pos_rey = t.buscar_rey(xFin, yFin, pos_rey_x, pos_rey_y);
    
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {

            TipoPieza t_posible_atacante = casillas[i][j]->getTipo();
            Colorpieza c_posible_atacante = casillas[i][j]->getColor();

            if ((int(t_posible_atacante) == 1 || int(t_posible_atacante) == 2 || int(t_posible_atacante) == 3 ||
                int(t_posible_atacante) == 4 || int(t_posible_atacante) == 5 || int(t_posible_atacante) == 6) &&
                c == c_posible_atacante)
            {
                
                bool aux = casillas[i][j]->movimientoValido(i, j, pos_rey_x, pos_rey_y, t);
                
                if (aux == true)
                    num_atacantes = num_atacantes + 1;
             
            }

        }
    }
    
    return num_atacantes;
}

int Tablero::posicion_atacante(int& pos_atac_x, int& pos_atac_y, Colorpieza c, int xFin, int yFin, Tablero& t)
{
    Pieza* pos_rey;
    int pos_rey_x, pos_rey_y, num_atacantes = 0;

    pos_rey = t.buscar_rey(xFin, yFin, pos_rey_x, pos_rey_y);

    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {

            TipoPieza t_posible_atacante = casillas[i][j]->getTipo();
            Colorpieza c_posible_atacante = casillas[i][j]->getColor();

            if ((int(t_posible_atacante) == 1 || int(t_posible_atacante) == 2 || int(t_posible_atacante) == 3 ||
                int(t_posible_atacante) == 4 || int(t_posible_atacante) == 5 || int(t_posible_atacante) == 6) &&
                c == c_posible_atacante)
            {

                bool aux = casillas[i][j]->movimientoValido(i, j, pos_rey_x, pos_rey_y, t);

                if (aux == true) {
                    pos_atac_x = i;
                    pos_atac_y = j;
                    return 0;
                }
            }
        }
    }

    return 0;
}

Pieza* Tablero::crearPieza(TipoPieza tipo, Colorpieza color) {
    switch (tipo) {
    case TipoPieza::REY: return new Rey(color);
    case TipoPieza::REINA: return new Reina(color);
    case TipoPieza::TORRE: return new Torre(color);
    case TipoPieza::ALFIL: return new Alfil(color);
    case TipoPieza::CABALLO: return new Caballo(color);
    case TipoPieza::PEON: return new Peon(color);
    default: return nullptr;
    }
}