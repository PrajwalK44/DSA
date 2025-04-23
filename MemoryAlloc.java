// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
class MemoryAlloc {
    
    static class Block {
        int size;
        boolean allocated = false;
        Block(int n) {
            this.size=n;
            this.allocated = false;
        }
    }
    
    public static void firstFit(int[] memoryBlocks, int[] processes){
        System.out.println("First fit ");
        Block[] blocks = new Block[memoryBlocks.length];
        for (int i = 0; i < memoryBlocks.length; i++) {
            blocks[i]=new Block(memoryBlocks[i]);
        }

        for (int i = 0; i < processes.length; i++) {
            boolean allocated = false;
            for (int j = 0; j < blocks.length; j++) {
                if(!blocks[j].allocated && blocks[j].size >= processes[i]){
                    int remSize = blocks[j].size - processes[i];
                    System.out.println("Process "+i+" of size "+processes[i]+ " had been allocated to block of size "+blocks[j].size);
                    if(remSize>0){
                        blocks[j].size = remSize;
                    } else blocks[j].allocated = true;
                    allocated = true;
                    break;
                }    
                if(!allocated) System.out.println("Proccess "+i+" of size "+processes[i]+" couldnt be allocated");
            }
        }
    }

    public static void bestFit(int[] memoryBlocks, int[] processes){
        System.out.println("Best fit");
        Block[] blocks = new Block[memoryBlocks.length];
        for (int i = 0; i < memoryBlocks.length; i++) {
            blocks[i] = new Block(memoryBlocks[i]); 
        }

        for (int i = 0; i < processes.length; i++) {
            int bestIndex = -1;
            for (int j = 0; j < blocks.length; j++) {
                if(!blocks[j].allocated && blocks[j].size>=processes[i]){
                    if(bestIndex == -1 || blocks[j].size < blocks[bestIndex].size){
                        bestIndex=j;
                    }
                }
            }

            if(bestIndex!=-1){
                int remSize = blocks[bestIndex].size - processes[i];
                System.out.println("Process "+i+" of size "+processes[i]+ " had been allocated to block of size "+blocks[bestIndex].size);
                if(remSize>0){
                    blocks[bestIndex].size = remSize;
                } else {
                    blocks[bestIndex].allocated = true;
                }
            }
            else {
                System.out.println("Process "+i+" of size "+processes[i]+ " couldnt be allocated.");
            }
        }
    }
    
    
    public static void worstFit(int[] memoryBlocks, int[] processes){
        System.out.println("Worst fit");
        Block[] blocks = new Block[memoryBlocks.length];
        for (int i = 0; i < memoryBlocks.length; i++) {
            blocks[i] = new Block(memoryBlocks[i]); 
        }

        for (int i = 0; i < processes.length; i++) {
            int worstIndex = -1;
            for (int j = 0; j < blocks.length; j++) {
                if(!blocks[j].allocated && blocks[j].size>=processes[i]){
                    if(worstIndex == -1 || blocks[j].size > blocks[worstIndex].size){
                        worstIndex=j;
                    }
                }
            }

            if(worstIndex!=-1){
                int remSize = blocks[worstIndex].size - processes[i];
                System.out.println("Process "+i+" of size "+processes[i]+ " had been allocated to block of size "+blocks[worstIndex].size);
                if(remSize>0){
                    blocks[worstIndex].size = remSize;
                } else {
                    blocks[worstIndex].allocated = true;
                }
            }
            else {
                System.out.println("Process "+i+" of size "+processes[i]+ " couldnt be allocated.");
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of blocks");
        int n = sc.nextInt();
        int[] memoryBlocks = new int[n];
        for(int i=0; i<n; i++){
            memoryBlocks[i]=sc.nextInt();
        }
        System.out.println("Enter the number of processes");
        int m = sc.nextInt();
        int[] processes = new int[m];
        for(int i=0; i<m; i++){
            processes[i]=sc.nextInt();
        }
        
        firstFit(memoryBlocks, processes);
        bestFit(memoryBlocks, processes);
        worstFit(memoryBlocks, processes);
    }
}