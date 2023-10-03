#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct coche{
    char placa[10];
    char *marca;
    char *color;
    char *hora;
};

struct cajon{
    int consecutivo;
    char id[10];
};

/*Secuencias para la entrada de un coche
 *      -- Cola de coches
 *  -> Alta coche
 *      - (Se capturan los datos e incrementa el contador)
 *
 *  -> Generación e impresión de comprobante
 *
 *  -- Cola de cajones
 *  -> Asigna y actualiza el cajon (opcional)   -Desencola-
 *
 */

/*Seuencias para la salida de un coche
 *  ->  Entrega de comprobante (recepción de comprobante)
 *  ->  Baja de coche
 *  ->  Cálculo de importe y pago
 *  ->  Impresión de comprobante de pago
 *  ->  Entrega y baja de comprobante de pago
 *  ->  Decrementa contador
 *  ->  Liberación del cajón (encolar)
 *
 *
 *
 */

int main(){


}
