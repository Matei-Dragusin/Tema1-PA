Colorare.cpp:
Am citit din fisier primul numar si tip de colorare pentru a determina valorea pe care "contor" o va avea la inceput. Apoi, la fiecare pas, am citit cate o pereche de tipul (numar, V/H) pe care am prelucrat-o. Functia modExp efectueaza ridicarile la putere, pentru numere foarte mari, eficient. Complexitatea temporala este O(n*log m), unde n este numarul de perechi din fisier, iar m este cea mai mare valoare din "number".

Compresie.cpp:
Pentru a rezolva aceasta problema, in momentul citirii datelor, am calculat suma fiecarui sir. Daca sumele sunt egale, atunci exista cel putin o varianta (worst case, se vor reduce la un singur element, suma totala). Am folosit cate un iterator pentru a parcurge fiecare lista, comparand sumele partiale la fiecare pas. De fiecare data cand gaseam o potrivire, incrementam contorul care reprezenta lungimea maxima pe care o poate avea sirul. Complexitatea temporala si spatiala a acestui algoritm este O(n+m), unde n si m sunt lungimile listelor. Complexitatea temporala este O(n*log n), unde n este numarul de cuvinte din fisier. 

Criptat.cpp:
Am initializat 2 vectori, unul pentru frecventa fiecarei litere in fiecare cuvant, iar unul pentru frecventa literelor in tot fisierul. Apoi, pentru fiecare litera, daca aceasta apare cel putin o data in fisier, adaug fiecare cuvant intr-un vector de perechi de tipul (lungime cuvant, frecventa litera), sortez dupa frecventa literei raportata la lungimea cuvantului, si, cat timp litera ramane dominanta, adaug cuvinte la parola nou creata. 

Oferta.cpp:
Am folosit programarea dinamica pentru a rezolva problema. dp[i] este costul minim pentru a cumpara 'i' produse. Cazurile de baza sunt dp[0] = 0 si dp[1] = prices[1]. Apoi, pentru fiecare element, incepand cu al doilea (caz separat), am verificat care dintre cele 3 grupari este mai ieftina. Complexitatea temporala este O(n), deoarece toata rezolvarea este facuta intr-o singura bucla, iar calculul fiecarei stari se realizeaza in O(1).
