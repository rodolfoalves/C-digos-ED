#include "funcs.h"
#include "banda.h"

int main(void){

	//ponteiros da estrutura banda de rock

	BR *elm;//ponteiro do nó que irá ser adicionado
    BR botaInt;
    BR *key;
    BR *key2;
    BR *show;

    //ponteiro para a lista
    DLlist *lista = NULL;

    //variáveis de busca
    char buscarNomeDaBanda[50], buscarNomeVocal[50];
    char rnBanda[50] , rnVocal[50];
    int ano;
    int rAno;
    float nota;
    float rNota;

	//variáveis auxiliares e do menu
	int i;
    void *data;
    int menu;
    int saida = 0;
	int menuRet;
	int menuInsere;

	//menu
    while(saida == 0){
	    printf("\nInforme a sua opcao?\n");
    	printf("1:Criar Lista\n");
    	printf("2:Inserir na Lista\n");
    	printf("3:Listar Todos\n");
    	printf("4:Pesquisar por Nome da Banda\n");
    	printf("5:Pesquisar por Nome do Vocalista\n");
    	printf("6:Pesquisar por Ano da Formacao\n");
    	printf("7:Pesquisar por Nota da Billboard\n");
    	printf("8:Remover Elemento da Lista\n");
    	printf("9:Destruir Lista\n");
    	printf("0:Sair\n");

		scanf("%d" ,&menu);

        switch(menu){
            case (1):{
            	if(lista != NULL){
            		printf("A lista ja esta criada\n");
            		break;
				}
				else{
					lista = dllCreate();
                	if(lista != NULL){
                	printf("LISTA CRIADA COM SUCESSO\n");
					}
                	break;
				}
           }

            case (2):{
            	if(lista != NULL){
	            	elm = (BR*)malloc(sizeof(BR));
	                printf("Informe os dados da banda de rock para inserir na lista\n");
	                fflush(stdin);
					printf("Nome:");
	                fflush(stdin);
					scanf("%s" ,elm->nomeBanda);//Salva o nome da banda
	                fflush(stdin);
					printf("Vocalista:");
	                fflush(stdin);
	                scanf("%s" ,elm->nomeVocal);//Salva o nome do vocalista
					fflush(stdin);
					printf("Ano de estreia:");
					fflush(stdin);
	                scanf("%d" ,&(elm->anoForm));//Salva o ano de formação
	                fflush(stdin);
					printf("Nota da Billboard:");
	                fflush(stdin);
	                scanf("%f" ,&(elm->notaBilb));//Salva a nota da Billboard
					fflush(stdin);

					dllInsereFirst(lista,elm);

					//printf("Agora digite 1 para inserir no começo ou 2 para inserir no final");
					//scanf("%d" ,menuInsere);

					//if(menuInsere == 1){
                        //dllInsereFirst(lista,elm);//Insere na primeira posição
                        //break;
					//}
					//else{
                        //dllInsereLast(lista,elm);//Insere na ultima posição
                        //break;
                        //}
	                //break;
            	}
            	else{
            		printf("A lista ainda n foi criada\n");
            		break;
				}
			}

			//Caso o uauário queira imprimir a lista
		    case (3):{
		    	if(lista != NULL){
	            	if(lista!=NULL){
	                    show=(BR*)dllGetFirst(lista);//Pega o primeiro elemento da lista
	                    while(show!=NULL){
	                        listaTodos(show);
	                        show=(BR*)dllGetNext(lista);
	                    }
	                }
	                else{
	                    printf("Lista vazia\n");
	                }
	                break;
	            }
	            else{
	            	printf("A lista ainda n foi criada\n");
	            	break;
				}
	        }

        	//Caso o usuário queira pesquisar na lista a partir do nome da banda de rock
            case (4):{
            	if(lista != NULL){
	                if (lista != NULL){
	                    printf("Informe nome da banda de rock a ser procurado:\n");
	                    fflush(stdin);
	                    scanf("%s", &buscarNomeDaBanda);
	                    data=dllQuery(lista,(void*)&buscarNomeDaBanda,ComparaNome);
	                    if(data != NULL){
	                    	printf("O elemento procurado esta na lista\n");
	                    }
	                    else{
	                        printf("O elemento procurado n esta na lista\n");
	                    }
	                }
	                else{
	                    printf("Lista vazia\n");
	                }
	                break;
            	}
            	else{
            		printf("A lita ainda não foi criada\n");
            		break;
				}
        	}

			//Caso o usuário queira pesquisar na lista a partir do nome do vocalista da banda
            case (5):{
            	if(lista != NULL){
	                if (lista!=NULL){
	                    printf("Informe nome do vocalista da banda de rock a ser procurado:\n");
	                    fflush(stdin);
	                    scanf("%s", &buscarNomeVocal);
	                    data=dllQuery(lista,(void*)&buscarNomeVocal,ComparaNomeVocal);

	                    if(data != NULL){
	                    	printf("O elemento procurado esta na lista\n");
	                    }
	                    else{
	                        printf("O elemento procurado n esta na lista\n");
	                    }
	                }
	                else{
	                    printf("Lista vazia\n");
	                }
	                break;
            }
            else{
            	printf("A lista ainda n foi criada\n");
            	break;
			}
		}
            //Caso o usuário queira pesquisar na lista a partir do ano de formação da banda
            case(6):{
            	if(lista != NULL){
	                if (lista != NULL){
	                    printf("Informe o ano de formacao da banda de rock a ser procurado:\n");
	                    fflush(stdin);
	                    scanf("%d", &ano);
	                    data=dllQuery(lista,(void*)&ano,ComparaAnoForm );
	                    if(data != NULL){
	                    	printf("O elemento procurado esta na lista\n");
	                    }
	                    else{
	                        printf("O elemento procurado n esta na lista\n");
	                    }
	                }
	                else{
	                    printf("Lista vazia\n");
	                }
	                break;
            	}
            	else{
            		printf("A lista ainda n foi criada\n");
            		break;
				}
            }

            //Caso o usuário queira pesquisar na lista a partir da nota da banda
            case(7):{
            	if (lista != NULL){

	            	if (lista!=NULL){
	                    printf("Informe a nota da Billboard da banda de rock a ser procurado:\n");
	                    fflush(stdin);
	                    scanf("%f", &nota);
	                    data=dllQuery(lista,(void*)&nota,ComparaNotaBilb);
	                    if(data != NULL){
	                    	printf("O elemento procurado esta na lista\n");
	                    }
	                    else{
	                        printf("O elemento procurado n esta na lista\n");
	                    }
	                }
	                else{
	                    printf("Lista vazia\n");
	                }
	                break;
				}
				else{
					printf("A lista ainda n foi criada\n");
					break;
				}
			}

			//Remove um elemento específico da lista
			case(8):{
				if(lista != NULL){

					//Informa de qual campo o usuário quer procurar na lista para remover uma Banda de Rock
					printf("Informe para qual campo vc quer procurar um elemento para remover:\n");
					printf("1: Nome:\n");
					printf("2: Vocalista:\n");
					printf("3: Ano de estreia:\n");
					printf("4: Nota da Billboard\n");
					scanf("%d" ,&menuRet);

					switch(menuRet){
						case(1):{//Remove a partir do nome da banda
							printf("Informe o nome da banda que vc quer retirar\n");
							fflush(stdin);
							scanf("%c" ,&rnBanda[50]);
							fflush(stdin);
							data=dllRemoveSpec(lista,(void*)&rnBanda,ComparaNome);

							if (data != NULL){//testa se o elemento foi realmente removido
								printf("Removido com sucesso\n");
							}
							break;
						}
						case(2):{//Remove a partir do nome do vocalista
							printf("Informe o nome do vocalista da banda que vc quer retirar\n");
							fflush(stdin);
							scanf("%c" ,&rnVocal[50]);
							fflush(stdin);
							data=dllRemoveSpec(lista,(void*)&rnVocal,ComparaNomeVocal);

							if (data != NULL){//testa se o elemento foi realmente removido
								printf("Removido com sucesso\n");
							}
							break;
						}
						case(3):{//Remove a partir do ano de fomação
							printf("Informe o ano de formacao da banda que vc quer retirar\n");
							fflush(stdin);
							scanf("%d" ,&rAno);
							fflush(stdin);
							data=dllRemoveSpec(lista,(void*)&rAno,ComparaAnoForm);

							if (data != NULL){//testa se o elemento foi realmente removido
								printf("Removido com sucesso\n");
							}
							break;
						}
						case(4):{//Remove a partir da nota da Billboard
							printf("Informe a nota da Billboard da banda que vc quer retirar\n");
							fflush(stdin);
							scanf("%f" ,&rNota);
							fflush(stdin);
							data=dllRemoveSpec(lista,(void*)&rNota,ComparaAnoForm);

							if (data != NULL){//testa se o elemento foi realmente removido
								printf("Removido com sucesso\n");
							}
							break;
						}
					}
				break;
			}
			else{
				printf("A lista ainda n foi criada\n");
				break;
			}
		}

			//Destroi a lista
			case(9):{
				if (lista != NULL){
					dllDestroy(lista);
					break;
				}
				else{
					printf("A lista ainda n foi criada\n");
					break;
				}

				break;
			}

			//Saída
			case(0):{
				saida = 1;
				break;
			}
        }
    }
    if(lista != NULL){
    	dllDestroy(lista);
	}
}

