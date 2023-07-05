class PrimeNumberCalculator implements Runnable { 
    private int start;     private int end;     private int count;     public PrimeNumberCalculator(int start, int end) { 
        this.start = start;         this.end = end;         this.count = 0; 
    } 
 
    private boolean isPrime(int num) { 
        if (num <= 1) {             return false; 
        } 
 
        for (int i = 2; i <= Math.sqrt(num); i++) {             if (num % i == 0) {                 return false; 
            } 
        } 
 
        return true; 
    } 
 
    public int getCount() {         return count; 
    } 
 
    @Override 
    public void run() {         for (int i = start; i <= end; i++) {             if (isPrime(i)) {                 count++; 
            } 
        } 
    } 
} 
 
public class Main {     public static void main(String[] args) throws InterruptedException { 
        int start = 1; 
        int end = 10000;         int segmentSize = 1000; 
 
        int threadCount = (int) Math.ceil((double) (end - start + 1) / segmentSize); 
        PrimeNumberCalculator[] calculators = new PrimeNumberCalculator[threadCount];         Thread[] threads = new Thread[threadCount]; 
 
        for (int i = 0; i < threadCount; i++) {             int segmentStart = start + (i * segmentSize);             int segmentEnd = Math.min(segmentStart + segmentSize - 1, end); 
 
            calculators[i] = new PrimeNumberCalculator(segmentStart, segmentEnd); 
            threads[i] = new Thread(calculators[i]); 
            threads[i].start(); 
        } 
 
        int totalCount = 0;         for (int i = 0; i < threadCount; i++) {             threads[i].join(); 
            totalCount += calculators[i].getCount(); 
        } 
 
        System.out.println("Total prime numbers: " + totalCount); 
    } 
} 
