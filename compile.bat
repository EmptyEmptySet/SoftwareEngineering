g++ ui.cpp -o temp/ui.o -c
g++ manager.cpp -o temp/manager.o -c
g++ main.cpp -o temp/main.o -c
g++ temp/main.o temp/ui.o temp/manager.o -o Ledger 
Ledger