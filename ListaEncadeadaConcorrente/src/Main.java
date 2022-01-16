public class Main {

    private static final int NUM_THREADS_INSERCAO = 10;
    private static final int NUM_THREADS_REMOCAO = 5;
    private static final int NUM_THREADS_BUSCA = 20;

    public static void main(String[] args) {
        ListaEncadeada lista = new ListaEncadeada();

        ThreadInsercao[] insercao = new ThreadInsercao[NUM_THREADS_INSERCAO];
        ThreadRemocao[] remocao = new ThreadRemocao[NUM_THREADS_REMOCAO];
        ThreadBusca[] busca = new ThreadBusca[NUM_THREADS_BUSCA];

        // Instancia��o das threads
        for (int i = 0; i < NUM_THREADS_INSERCAO; i++) {
            insercao[i] = new ThreadInsercao("Inserção #" + (i+1), lista, i+1);
        }
        for (int i = 0; i < NUM_THREADS_REMOCAO; i++) {
            remocao[i] = new ThreadRemocao("Remoção #" + (i+1), lista, i+1);
        }
        for (int i = 0; i < NUM_THREADS_BUSCA; i++) {
            busca[i] = new ThreadBusca("Busca #" + (i+1), lista, i+1);
        }

        // Coloca as threads em execu��o
        for (int i = 0; i < NUM_THREADS_INSERCAO; i++) {
            insercao[i].start();
        }
        for (int i = 0; i < NUM_THREADS_BUSCA; i++) {
            busca[i].start();
        }
        for (int i = 0; i < NUM_THREADS_REMOCAO; i++) {
            remocao[i].start();
        }

        // Espera o fim da execução das threads
        try {
            for (int i = 0; i < NUM_THREADS_INSERCAO; i++) {
                insercao[i].join();
            }
            for (int i = 0; i < NUM_THREADS_REMOCAO; i++) {
                remocao[i].join();
            }
            for (int i = 0; i < NUM_THREADS_BUSCA; i++) {
                busca[i].join();
            }
        } catch (InterruptedException e){
            e.printStackTrace();
        }

        System.out.println("\nFim de execução do programa!");

    }
}