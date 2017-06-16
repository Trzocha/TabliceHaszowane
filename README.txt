# TabliceHaszowane
Tablice haszowane

Napisz program śledzący ilość przelanych pieniędzy. Na wejście podane będą polecenia w formacie:
+ od do ile - od wpłaca na konto do ile pieniędzy
? od do - polecenie wypisania na ekran dotychczasowej sumy pieniędzy przelanych przez od na konto do

Uwaga: nie należy liczyć stanu konta, tylko sumę przelanych pieniędzy:
+ A B 10
+ A B 10
+ B A 5
? A B
? B A
powinno wypisać:
20
5

Nazwy od i do będą napisami składającymi się z maksymalnie 16 małych liter i znaku podkreślenia. Suma wpłat dla każdej pary nie 
przekroczy zakresu int-a.
Należy skorzystać z tablicy haszowanej z łańcuchowaniem oddzielnym do rozwiązywania kolizji

Przykład

Wejście:
+ rychu miro 10
+ marek_d tomek 100
+ marek_d lew 20
+ lew adam 17
+ miro rychu 10
? rychu miro
? marek_d tomek
? marek_d lew
? lew adam
? miro rychu
? tomek marek_d
? lew marek_d
? adam lew

Wyjście:
10
100
20
17
10
0
0
0
