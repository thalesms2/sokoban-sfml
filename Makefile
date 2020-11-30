CXXARGS = -Wall -Wextra -std=c++17 -lsfml-graphics -lsfml-window -lsfml-system
NOMEPROG = sokoban-app

ARQUIVO = source.cpp

#alvo: dependencia outroalvo arquivo (3 alvos: compilar, debug, limpar arquivos)
#	#acao
#make compilar
compilar: $(ARQUIVO) #dependencia
	g++ -c $(ARQUIVO)
	g++ $(ARQUIVO) -o $(NOMEPROG) $(CXXARGS)

#make debug no terminal do linux
debug: $(ARQUIVO)
	g++ $(ARQUIVO) -o $(NOMEPROG) $(CXXARGS) -g

apagar:
	rm $(NOMEPROG)

e: compilar
	./$(NOMEPROG)


#no meu programa precisa dar make executar pra executar

