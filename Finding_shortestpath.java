import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        int R = s.nextInt();

        Map<Integer, List<int[]>> g = new HashMap<>();

        while (R-- > 0) {
            int a = s.nextInt();
            int b = s.nextInt();
            int dist = s.nextInt();

            g.putIfAbsent(a, new ArrayList<>());
            g.putIfAbsent(b, new ArrayList<>());

            g.get(a).add(new int[]{b, dist});
            g.get(b).add(new int[]{a, dist});
        }

        int st = s.nextInt();
        int end = s.nextInt();

        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (x, y) -> x[0] - y[0]
        );

        Map<Integer, Integer> distance = new HashMap<>();

        distance.put(st, 0);
        pq.add(new int[]{0, st});

        while (!pq.isEmpty()) {

            int[] curr = pq.poll();

            int d = curr[0];
            int city = curr[1];

            if (d != distance.get(city))
                continue;

            if (city == end)
                break;

            for (int[] next : g.getOrDefault(city, new ArrayList<>())) {

                int nextCity = next[0];
                int weight = next[1];

                int newDist = d + weight;

                if (!distance.containsKey(nextCity)
                        || newDist < distance.get(nextCity)) {

                    distance.put(nextCity, newDist);
                    pq.add(new int[]{newDist, nextCity});
                }
            }
        }

        if (distance.containsKey(end))
            System.out.println(distance.get(end));
        else
            System.out.println(-1);
    }
}
