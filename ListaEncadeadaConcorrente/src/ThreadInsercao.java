public class ThreadInsercao extends Thread{
    private ListaEncadeada lista;
    private int elemento;

    public ThreadInsercao(String nome, ListaEncadeada lista, int elemento){
        super(nome);
        this.lista = lista;
        this.elemento = elemento;
    }

    @Override
    public void run(){
        lista.insereElemento(elemento, this.getName());
    }
}