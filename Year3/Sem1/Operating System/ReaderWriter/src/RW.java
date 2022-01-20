/*
       Read Access  	If no threads are writing, and no threads have requested write access.
       Write Access   	If no threads are reading or writing.

       read to read - A thread is granted read reentrance if it can get read access (no writers or write requests), or if it already has read access (regardless of write requests).
       write to write - Write reentrance is granted only if the thread has already write access.
       Read to write - the thread must be the only reader.
       write to read - A writer should always be granted read access if requested. If a thread has write access no other threads can have read nor write access, so it is not dangerous
*/


import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class ReadWriteLock {
    private static int val;
    private final Map<Thread, Integer> readingThreads =
            new HashMap<>();
    private int writeAccesses = 0;
    private int writeRequests = 0;
    private Thread writingThread = null;

    ReadWriteLock() {
        val = 0;
    }
    public synchronized void lockRead() throws InterruptedException {
        Thread callingThread = Thread.currentThread();
        while (!canGrantReadAccess(callingThread)) {
            wait();
        }

        readingThreads.put(callingThread,
                (getReadAccessCount(callingThread) + 1));
    }

    private boolean canGrantReadAccess(Thread callingThread) {
        if (isWriter(callingThread)) return true;
        if (hasWriter()) return false;
        if (isReader(callingThread)) return true;
        return !hasWriteRequests();
    }


    public synchronized void unlockRead() {
        Thread callingThread = Thread.currentThread();
        if (!isReader(callingThread)) {
            throw new IllegalMonitorStateException("Calling Thread does not" +
                    " hold a read lock on this ReadWriteLock");
        }
        int accessCount = getReadAccessCount(callingThread);
        if (accessCount == 1) {
            readingThreads.remove(callingThread);
        } else {
            readingThreads.put(callingThread, (accessCount - 1));
        }
        notifyAll();
    }

    public synchronized void lockWrite() throws InterruptedException {
        writeRequests++;
        Thread callingThread = Thread.currentThread();
        while (!canGrantWriteAccess(callingThread)) {
            wait();
        }
        writeRequests--;
        writeAccesses++;
        writingThread = callingThread;
    }

    public synchronized void unlockWrite() {
        if (!isWriter(Thread.currentThread())) {
            throw new IllegalMonitorStateException("Calling Thread does not" +
                    " hold the write lock on this ReadWriteLock");
        }
        writeAccesses--;
        if (writeAccesses == 0) {
            writingThread = null;
        }
        notifyAll();
    }

    private boolean canGrantWriteAccess(Thread callingThread) {
        if (isOnlyReader(callingThread)) return true;
        if (hasReaders()) return false;
        if (writingThread == null) return true;
        return isWriter(callingThread);
    }


    private int getReadAccessCount(Thread callingThread) {
        Integer accessCount = readingThreads.get(callingThread);
        if (accessCount == null) return 0;
        return accessCount;
    }


    private boolean hasReaders() {
        return readingThreads.size() > 0;
    }

    private boolean isReader(Thread callingThread) {
        return readingThreads.get(callingThread) != null;
    }

    private boolean isOnlyReader(Thread callingThread) {
        return readingThreads.size() == 1 &&
                readingThreads.get(callingThread) != null;
    }

    private boolean hasWriter() {
        return writingThread != null;
    }

    private boolean isWriter(Thread callingThread) {
        return writingThread == callingThread;
    }

    private boolean hasWriteRequests() {
        return this.writeRequests > 0;
    }

    public void read(int id) {
        try {
            lockRead();
            System.out.println("I  Reader "+id+" Have started Reading the value " + val);
            Thread.sleep((int) (Math.random() * 500));
            System.out.println("Done Reading the value " + val);
        } catch (Exception e) {
            System.exit(1);
        } finally {
            unlockRead();
        }
    }

    public void write(int id) {
        try {
            lockWrite();
            System.out.println("I Writer "+id+" have started Writing the value " + val);
            Thread.sleep((int) (Math.random() * 500));
            val = val + 1;
            System.out.println("Done Writing the value " + val);
        } catch (Exception e) {
            System.exit(1);
        } finally {
            unlockWrite();
        }
    }
}


class Reader extends Thread {
    final ReadWriteLock readWriteLock;
    final int id ;
    Reader(ReadWriteLock readWriteLock, int id) {
        this.readWriteLock = readWriteLock;
        this.id = id;
    }

    @Override
    public void run() {
        try {
            Thread.sleep((int) (Math.random() * 5000));
            readWriteLock.read(id);
        } catch (InterruptedException ignored) {
        }
    }
}

class Writer extends Thread {
    final ReadWriteLock readWriteLock;
    final int id ;

    Writer(ReadWriteLock readWriteLock, int id) {
        this.readWriteLock = readWriteLock;
        this.id = id;
    }

    @Override
    public void run() {
        try {
            Thread.sleep((int) (Math.random() * 5000));
            readWriteLock.write(id);

        } catch (InterruptedException ignored) {
        }

    }
}

public class RW {
    public static void main(String[] args) {
        int numOfWriters, numOfReaders;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter num of Writers and Readers : ");
        numOfWriters = Integer.parseInt(in.nextLine());
        numOfReaders = Integer.parseInt(in.nextLine());
        ReadWriteLock readWriteLock = new ReadWriteLock();


        for (int i = 0; i < numOfReaders; i++) {
            new Reader(readWriteLock,i).start();
        }
        for (int i = 0; i < numOfWriters; i++) {
            new Writer(readWriteLock,i).start();
        }

    }
}