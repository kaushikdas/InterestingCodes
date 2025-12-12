package kaushik.java.hackerrank;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Arrays;

public class TripletSolution {
  static long countTriplets(List<Long> arr, long r) {
    Long[] A = new Long[arr.size()];
    arr.toArray(A);

    HashMap<Long, ArrayList<Long>> hm = new HashMap<>();

    long result = 0;

    // Iterate the list in revese order from end
    for (int i = A.length-1; i >= 0; --i) {
      ArrayList<Long> triplet;

      if ((triplet = hm.get(A[i]*r*r)) != null) {
        result += triplet.get(3);
      }

      if ((triplet = hm.get(A[i]*r)) != null) {
        long f = triplet.get(1);
        triplet.set(1, f+1);
        long c = triplet.get(2);
        triplet.set(3, triplet.get(3)+triplet.get(2));
      }

      if ((triplet = hm.get(A[i])) != null) {
        long f = triplet.get(2);
        triplet.set(0, 0L);
        triplet.set(1, 0L);
        triplet.set(2, f+1);
      }
      else {
        triplet = new ArrayList<Long>();

        triplet.add(0L);
        triplet.add(0L);
        triplet.add(1L);
        triplet.add(0L);

        hm.put(A[i], triplet);
      }
    }

    return result;
  }

  static long countTriplets2(List<Long> arr, long r) {
    Long[] A = new Long[arr.size()];
    arr.toArray(A);

    HashMap<Long, ArrayList<Integer>> hm = new HashMap<>();

    long result = 0;

    // Iterate the list in revese order from end
    for (int i = A.length-1; i >= 0; --i) {
      ArrayList<Integer> triplet;

      if ((triplet = hm.get(A[i]*r*r)) != null) {
        result += triplet.get(3);
      }

      if ((triplet = hm.get(A[i]*r)) != null) {
        int f = triplet.get(1);
        triplet.set(1, f+1);
        long c = triplet.get(2);
        triplet.set(3, triplet.get(3)+triplet.get(2));
      }

      if ((triplet = hm.get(A[i])) != null) {
        int f = triplet.get(2);
        triplet.set(0, 0);
        triplet.set(1, 0);
        triplet.set(2, f+1);
      }
      else {
        triplet = new ArrayList<Integer>();

        triplet.add(0);
        triplet.add(0);
        triplet.add(1);
        triplet.add(0);

        hm.put(A[i], triplet);
      }
    }

    return result;
  }

  public static void main(String[] args) {
    List<Long> arr;
    /*
    arr = Arrays.asList(1L, 2L, 2L, 4L);
    System.out.println(countTriplets(arr, 2));

    arr = Arrays.asList(1L, 3L, 9L, 9L, 27L, 81L);
    System.out.println(countTriplets(arr, 3));

    arr = Arrays.asList(1L, 5L, 5L, 25L, 125L);
    System.out.println(countTriplets(arr, 5));

    arr = Arrays.asList(1L, 3L, 9L, 2L, 1L, 3L, 9L);
    System.out.println(countTriplets(arr, 3));

    arr = Arrays.asList(3L, 3L, 3L, 3L, 3L);
    System.out.println(countTriplets(arr, 1));

    arr = Arrays.asList(1237L, 1237L, 1237L, 1237L, 1237L);
    System.out.println(countTriplets(arr, 1));
     */

    arr = new ArrayList<>();
    for (int i = 0; i < 100000; i++)
      arr.add(1237L);
    System.out.println(countTriplets(arr, 1));

    /*
    arr = new ArrayList<>();
    for (int i = 0; i < 100000; i++)
      arr.add(1237L);
    System.out.println(countTriplets(arr, 1)); // expected 166661666700000
     */

    // expected 166661666700000
    // expected 18644208777952
  }
}
