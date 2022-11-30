import java.util.concurrent.atomic.AtomicInteger;

class CSC450_Portfolio_Project{
    public static void main(String[] args) {
        AtomicInteger sharedNum = new AtomicInteger(100);

        countDown countDown = new countDown(sharedNum);
        countDown.run();
        countUp countUp = new countUp(sharedNum);
        countUp.run();
    }

}


class countDown implements Runnable{
    static final int targetNum = 0;
    AtomicInteger currentNum;

    countDown(AtomicInteger sharedNum){
        this.currentNum = sharedNum;
    }
    @Override
    public void run(){
        while (currentNum.get() > targetNum){
            System.out.print(currentNum.getAndDecrement() + " ");            
        }
        System.out.print(currentNum.get());
        System.out.println("\nDone counting down!");
    }
}

class countUp implements Runnable{
    static final int targetNum = 100;
    AtomicInteger currentNum;

    countUp(AtomicInteger sharedNum){
        this.currentNum = sharedNum;
    }
    @Override
    public void run(){
        while (currentNum.get() < targetNum){
            System.out.print(currentNum.getAndIncrement() + " ");            
        }
        System.out.print(currentNum.get());
        System.out.println("\nDone counting up!");
    }
}