#include "komplex.h"

KOMPEX scitaj(KOMPEX x, KOMPEX y){
KOMPEX pom;
pom.real = x.real + y.real;
pom.imag = x.imag + y.imag;

return(pom);
}

KOMPEX odcitaj(KOMPEX x, KOMPEX y){
KOMPEX pom;
pom.real = x.real - y.real;
pom.imag = x.imag - y.imag;

return(pom);
}
