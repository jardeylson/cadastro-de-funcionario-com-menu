#include <iostream>

using namespace std;

struct funcionario{
    int identificacao, idade;
    struct funcionario *prox;
};

void instancia_lista(funcionario* &f){
    f= NULL;
}

void inserir_inicio(funcionario* &f, int identificacao, int idade){
    funcionario *novo;
    novo = new funcionario;
    novo -> identificacao = identificacao;
    novo -> idade = idade;
    novo -> prox = NULL;
    if (f == NULL){
        f = novo;
    }else{
        novo->prox = f;
        f = novo;
    }
}

void imprimir (funcionario* f){
    while(f != NULL){
        cout <<"identificacao " << f->identificacao << ", idade "<< f->idade << endl;
        f = f->prox;
    }
}

int tamanho (funcionario* f){
    int cont = 0;
    while(f != NULL){
        cont++;
        f = f->prox;
    }
    return cont;
}

bool inserirPos(funcionario*&f, int id, int idade, int pos){
    int tam = tamanho(f);
    if (pos > tam+1 ){
        return false;
    }else{
        funcionario* novo = new funcionario;
        novo->identificacao = id;
        novo->idade = idade;
        novo->prox = NULL;
        if( pos == 1){
            novo->prox = f;
            f = novo;
        }else if(pos == tam+1 ){
            funcionario* perc = f;
            while(perc->prox != NULL){
                perc = perc->prox;
            }
            perc->prox = novo;
        }else{
            funcionario* perc = f;
            int cont = 1;
            while(cont != pos-1 ){
                perc = perc->prox;
                cont++;
            }
            novo->prox = perc->prox;
            perc -> prox = novo;
        }
        return true;
    }
}

int menu (int &x){
    cout << "\n" << "1-adicinar funcionario"
    << "\n" << "2-imprimir a lista de funcionarios"
    << "\n"<< "3-exibir a quantidade de funcionarios"
    << "\n" << "4-adicionar funcionario em uma determinada posicao"
    << "\n" << "5-sair" << endl;
    cin >> x;

    return x;
}

int main(){

    funcionario* f1;
    instancia_lista(f1);
    int identificacao, idade,pos, n;

    cout << "bem vindo ao gerenciador de funcionarios" << endl;

    while(n!=5){
        menu(n);

        if (n == 1){
            cout << "\n" << "identificacao do funcionario: ";
            cin >> identificacao;
            cout << "idade do funcionario: ";
            cin >> idade;
            inserir_inicio(f1,identificacao,idade);
        }else if(n == 2){
            cout << "\n" << "lista de funcionarios" << endl;
            imprimir(f1);
        }else if (n == 3){
            cout << "quantidade de funcionarios: " << tamanho(f1) << endl;
        }else if(n == 4){
            cout << "\n" << "identificacao do funcionario: ";
            cin >> identificacao;
            cout << "idade do funcionario: ";
            cin >> idade;
            cout << "qual a posicao inserir o novo funcionario:";
            cin >> pos;
            inserirPos(f1,identificacao,idade,pos);
            if(inserirPos(f1,identificacao,idade,pos) == true){
                cout << "funcionario inserido" << endl;
            }else{
                cout << "posicao invalida" << endl;
            }
        }
    }

    return 0;
}
