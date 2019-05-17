import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        // 使用LinkedList创建并初始化一个队列 
        Queue<String> waitingQueue = new LinkedList<>();

        //给队列添加元素（Enqueue 操作）
        waitingQueue.add("Rajeev");
        waitingQueue.add("Chris");
        waitingQueue.add("John");
        waitingQueue.add("Mark");
        waitingQueue.add("Steven");

        System.out.println("WaitingQueue : " + waitingQueue);

        // 从队列中删除元素（ Dequeue操作）
        // 使用remove()方法删除元素时候，如果队列是空的，会抛出NoSuchElementException异常
        String name = waitingQueue.remove();
        System.out.println("Removed from WaitingQueue : " + name + " | New WaitingQueue : " + waitingQueue);

        // 使用poll()方法删除队列中的元素 
        //poll()方法和remove()相似，唯一的区别是当队列为空时候poll()返回null
        name = waitingQueue.poll();
        System.out.println("Removed from WaitingQueue : " + name + " | New WaitingQueue : " + waitingQueue);
    }
}