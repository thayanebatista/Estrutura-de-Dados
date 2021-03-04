#include <iostream>

using namespace std;

struct noListaSE
{
    int chave;
    noListaSE *prox;
};

struct ListaSE
{
    noListaSE *ultimo, *primeiro;
};

void inicializa_lista(ListaSE &l)
{
    l.ultimo = NULL;
    l.primeiro = NULL;
}


bool lista_vazia(ListaSE &l)
{
    return (l.primeiro==NULL);
}


noListaSE* busca_lista(ListaSE &l, int x)
{
    noListaSE *no;

    if (lista_vazia(l))
    {
        return NULL;
    }
    else
    {
        no = l.primeiro;
        while (no!=l.ultimo && no->chave!=x)
        {
            no = no->prox;
        }
        if (no->chave==x)
        {
            return no;
        }
        else
        {
            return NULL;
        }
    }
}


void inserefim_lista(ListaSE &l, int x)
{
    noListaSE *novo = new noListaSE();

    if(novo == NULL)
    {
        cout<<"\n  LISTA CHEIA\n";
    }
    else
    {
        novo->chave = x;
        if (lista_vazia(l))
        {
            novo->prox = NULL;
            l.primeiro = novo;

        }
        else
        {
            l.ultimo->prox = novo;
            novo->prox = NULL;
        }
        l.ultimo = novo;
    }
}


void insereinicio_lista(ListaSE &l, int x)
{
    noListaSE *novo = new noListaSE();

    if(novo == NULL)
    {
        cout<<"\n   LISTA CHEIA  \n";
    }
    else
    {
        novo->chave = x;
        if (lista_vazia(l))
        {
            novo->prox = NULL;
            l.ultimo = novo;
        }
        else
        {
            novo->prox = l.primeiro;
        }
        l.primeiro = novo;
    }
}


void insereordenado_lista(ListaSE &l, int x)
{
    if (lista_vazia(l) || l.primeiro->chave >= x)
    {
        insereinicio_lista(l,x);
    }
    else if (l.ultimo->chave <= x)
    {
        inserefim_lista(l,x);
    }
    else
    {
        noListaSE *novo = new noListaSE();
        noListaSE *aux;
        if(novo == NULL)
        {
            cout<<"\n   LISTA CHEIA  \n";
            return;
        }
        else
        {
            novo->chave = x;
            aux = l.primeiro;

            while (aux->prox->chave < x)
            {
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
    }
}


noListaSE* remove_lista(ListaSE &l, int x)
{
    if (!lista_vazia(l))
    {

        noListaSE *no;
        no = busca_lista(l,x);
        if (l.primeiro == l.ultimo)
        {
            inicializa_lista(l);
        }
        else
        {
            if(no == NULL)
            {
                return NULL;
            }
            else if (no==l.primeiro)
            {
                l.primeiro = l.primeiro->prox;
            }
            else
            {
                noListaSE *aux;
                aux = l.primeiro;
                while (aux->prox!=no)
                {
                    aux = aux->prox;
                }
                aux->prox = no->prox;
                if (l.ultimo==no)
                {
                    l.ultimo = aux;
                }
            }
        }
        return no;
    }
    else
    {
        cout<<"\n     LISTA VAZIA   "<<endl;
        system("pause");
        return NULL;
    }

}


void inseresemrepeticao_lista(ListaSE &l, int x)
{
    if (busca_lista(l,x)==NULL)
    {
        insereinicio_lista(l,x);
    }
    else
    {
        cout<<"\n    NAO FOI POSSIVEL INSERIR, ELEMENTO JA EXISTENTE \n\n";
        system("pause");
    }
}


void imprime_lista(ListaSE &l)
{
    noListaSE *aux;
    if (lista_vazia(l))
    {
        cout<<"\n   LISTA VAZIA \n";
        system("pause");
        return;
    }

    aux = l.primeiro;

    system("cls");

    cout<<endl<<"   ";
    while (aux != l.ultimo)
    {
        cout<<aux->chave<<" | ";
        aux = aux->prox;
    }
    cout<<aux->chave;
    cout<<endl<<endl;
    system("pause");
}


