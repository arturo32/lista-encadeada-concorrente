public class ThreadRemocao extends Thread{
    private ListaEncadeada lista;
    private int elemento;

    public ThreadRemocao(String nome, ListaEncadeada lista, int elemento){
        super(nome);
        this.lista = lista;
        this.elemento = elemento;
    }

    @Override
    public void run(){
        lista.removeElemento(elemento, this.getName());
    }
}