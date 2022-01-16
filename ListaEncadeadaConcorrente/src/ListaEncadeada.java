import java.util.LinkedList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class ListaEncadeada {

    private LinkedList<Integer> lista;
    private ReentrantReadWriteLock lock;
    private Lock leitura;
    private Lock escrita;

    public ListaEncadeada(){
        lista = new LinkedList<>();
        lock = new ReentrantReadWriteLock(true);
        leitura = lock.readLock();
        escrita = lock.writeLock();
    }

    public void buscaElemento(int elemento, String nomeThread){
        System.out.println(nomeThread + ": tentou bloquear o readLock.");
        leitura.lock();
        System.out.println(nomeThread + ": bloqueou o readLock.");
        try {
            int posicao = lista.indexOf(elemento);
            if(posicao != -1){
                System.out.println("\t" + nomeThread + ": elemento " + elemento + " encontrado no posição " + posicao + ".");
            }else{
                System.out.println("\t" + nomeThread + ": elemento " + elemento + " não encontrado.");
            }
        } catch (Exception e){
            e.printStackTrace();
        } finally {
            System.out.println(nomeThread + ": liberou o readLock.");
            leitura.unlock();
        }
    }

    public void insereElemento(int elemento, String nomeThread){
        System.out.println(nomeThread + ": tentou bloquear o writeLock.");
        escrita.lock();
        System.out.println(nomeThread + ": bloqueou o writeLock.");
        try {
            lista.add(elemento);
            System.out.println("\t" + nomeThread + ": elemento " + elemento + " inserido.");
        } catch (Exception e){
            e.printStackTrace();
        } finally {
            System.out.println(nomeThread + ": liberou o writeLock.");
            escrita.unlock();
        }
    }

    public void removeElemento(int elemento, String nomeThread){
        System.out.println(nomeThread + ": tentou bloquear o writeLock.");
        escrita.lock();
        System.out.println(nomeThread + ": bloqueou o writeLock.");
        try {
            boolean sucesso = lista.remove((Integer) elemento);
            if(sucesso)
                System.out.println("\t" + nomeThread + ": elemento " + elemento + " removido.");
            else{
                System.out.println("\t" + nomeThread + ": elemento " + elemento + " inexistente, remoção não realizada.");
            }
        } catch (Exception e){
            e.printStackTrace();
        } finally {
            System.out.println(nomeThread + ": liberou o writeLock.");
            escrita.unlock();
        }
    }

}