import java.util.*;

public class DiskScheduling {
    public static void fcfs(int[] requests, int head) {
        int seek = 0;
        int distance;
        int current = head;
        System.out.print("FCFS Order: ");
        for (int i = 0; i < requests.length; i++) {
            System.out.print(requests[i] + " ");
            distance = Math.abs(requests[i] - current);
            seek += distance;
            current = requests[i];
        }
        System.out.println("\nTotal seek operations: " + seek);
    }

    public static void sstf(int[] requests, int head) {
        boolean[] visited = new boolean[requests.length];
        int seek = 0;
        int current = head;
        System.out.print("SSTF Order: ");
        for (int i = 0; i < requests.length; i++) {
            int min = Integer.MAX_VALUE;
            int index = -1;
            for (int j = 0; j < requests.length; j++) {
                if (!visited[j]) {
                    int diff = Math.abs(requests[j] - current);
                    if (diff < min) {
                        min = diff;
                        index = j;
                    }
                }
            }
            visited[index] = true;
            seek += Math.abs(requests[index] - current);
            current = requests[index];
            System.out.print(current + " ");
        }
        System.out.println("\nTotal seek operations: " + seek);
    }

    public static void scan(int[] requests, int head, int diskSize, boolean directionRight) {
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        int seek = 0;
        int current = head;

        for (int r : requests) {
            if (r < head)
                left.add(r);
            else
                right.add(r);
        }

        Collections.sort(left);
        Collections.sort(right);
        System.out.print("SCAN Order: ");

        if (!directionRight) {
            for (int i = left.size() - 1; i >= 0; i--) {
                System.out.print(left.get(i) + " ");
                seek += Math.abs(current - left.get(i));
                current = left.get(i);
            }
            if (current != 0) {
                seek += current;
                current = 0;
            }
            for (int r : right) {
                System.out.print(r + " ");
                seek += Math.abs(r - current);
                current = r;
            }
        } else {
            for (int r : right) {
                System.out.print(r + " ");
                seek += Math.abs(r - current);
                current = r;
            }
            if (current != diskSize - 1) {
                seek += (diskSize - 1 - current);
                current = diskSize - 1;
            }
            for (int i = left.size() - 1; i >= 0; i--) {
                System.out.print(left.get(i) + " ");
                seek += Math.abs(current - left.get(i));
                current = left.get(i);
            }
        }
        System.out.println("\nTotal seek operations: " + seek);
    }

    public static void cscan(int[] requests, int head, int diskSize, boolean directionRight) {
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        int seek = 0;
        int current = head;

        for (int r : requests) {
            if (r < head)
                left.add(r);
            else
                right.add(r);
        }

        Collections.sort(left);
        Collections.sort(right);
        System.out.print("C-SCAN Order: ");

        if (directionRight) {
            for (int r : right) {
                System.out.print(r + " ");
                seek += Math.abs(current - r);
                current = r;
            }
            if (current != diskSize - 1) {
                seek += (diskSize - 1 - current);
                current = 0;
                seek += diskSize - 1;
            }
            for (int r : left) {
                System.out.print(r + " ");
                seek += Math.abs(current - r);
                current = r;
            }
        } else {
            for (int i = left.size() - 1; i >= 0; i--) {
                System.out.print(left.get(i) + " ");
                seek += Math.abs(current - left.get(i));
                current = left.get(i);
            }
            if (current != 0) {
                seek += current;
                current = diskSize - 1;
                seek += current;
            }
            for (int i = right.size() - 1; i >= 0; i--) {
                System.out.print(right.get(i) + " ");
                seek += Math.abs(current - right.get(i));
                current = right.get(i);
            }
        }
        System.out.println("\nTotal seek operations: " + seek);
    }

    public static void look(int[] requests, int head, boolean directionRight) {
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        int seek = 0;
        int current = head;

        for (int r : requests) {
            if (r < head)
                left.add(r);
            else
                right.add(r);
        }

        Collections.sort(left);
        Collections.sort(right);
        System.out.print("LOOK Order: ");

        if (!directionRight) {
            for (int i = left.size() - 1; i >= 0; i--) {
                System.out.print(left.get(i) + " ");
                seek += Math.abs(current - left.get(i));
                current = left.get(i);
            }
            for (int r : right) {
                System.out.print(r + " ");
                seek += Math.abs(r - current);
                current = r;
            }
        } else {
            for (int r : right) {
                System.out.print(r + " ");
                seek += Math.abs(r - current);
                current = r;
            }
            for (int i = left.size() - 1; i >= 0; i--) {
                System.out.print(left.get(i) + " ");
                seek += Math.abs(current - left.get(i));
                current = left.get(i);
            }
        }
        System.out.println("\nTotal seek operations: " + seek);
    }

    public static void clook(int[] requests, int head, boolean directionRight) {
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        int seek = 0;
        int current = head;

        for (int r : requests) {
            if (r < head)
                left.add(r);
            else
                right.add(r);
        }

        Collections.sort(left);
        Collections.sort(right);
        System.out.print("C-LOOK Order: ");

        if (directionRight) {
            for (int r : right) {
                System.out.print(r + " ");
                seek += Math.abs(current - r);
                current = r;
            }

            if (!left.isEmpty()) {
                seek += Math.abs(current - left.get(0));
                current = left.get(0);

                for (int r : left) {
                    System.out.print(r + " ");
                    seek += Math.abs(current - r);
                    current = r;
                }
            }
        } else {
            for (int i = left.size() - 1; i >= 0; i--) {
                System.out.print(left.get(i) + " ");
                seek += Math.abs(current - left.get(i));
                current = left.get(i);
            }

            if (!right.isEmpty()) {
                seek += Math.abs(current - right.get(right.size() - 1));
                current = right.get(right.size() - 1);

                for (int i = right.size() - 1; i >= 0; i--) {
                    System.out.print(right.get(i) + " ");
                    seek += Math.abs(current - right.get(i));
                    current = right.get(i);
                }
            }
        }

        System.out.println("\nTotal seek operations: " + seek);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of requests: ");
        int n = sc.nextInt();
        int[] requests = new int[n];

        System.out.println("Enter the requests: ");
        for (int i = 0; i < n; i++) {
            requests[i] = sc.nextInt();
        }

        System.out.print("Enter initial head position: ");
        int head = sc.nextInt();

        System.out.print("Enter disk size: ");
        int diskSize = sc.nextInt();

        System.out.print("Choose direction (0: left, 1: right): ");
        boolean directionRight = sc.nextInt() == 1;

        System.out.println("\n---- Disk Scheduling Algorithms ----");
        fcfs(requests, head);
        sstf(requests, head);
        scan(requests, head, diskSize, directionRight);
        cscan(requests, head, diskSize, directionRight);
        look(requests, head, directionRight);
        clook(requests, head, directionRight);
    }
}

