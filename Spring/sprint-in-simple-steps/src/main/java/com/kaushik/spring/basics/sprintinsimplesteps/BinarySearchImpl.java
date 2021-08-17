package com.kaushik.spring.basics.sprintinsimplesteps;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

public class BinarySearchImpl implements SearchAlgorithm {

  private SortAlgorithm sortAlgo;

  public BinarySearchImpl(SortAlgorithm sortAlgo) {
    this.sortAlgo = sortAlgo;
  }

  private boolean _search(int[] a, int lo, int hi, int k) {
    if (lo > hi) {
      return false;
    }
    int mid = (lo + hi) >> 1;
    if (a[mid] == k) {
      return true;
    }
    else if (a[mid] < k) {
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
    return _search(a, lo, hi, k);
  }

  public boolean search(int[] a, int k) {
    // sort a
    /*
        System.out.println("Before sort");
        for (int i : a) {
          System.out.print(i + " ");
        }
        System.out.println();
    */

    sortAlgo.sort(a);

    /*
        System.out.println("After sort");
        for (int i : a) {
          System.out.print(i + " ");
        }
        System.out.println();
    */

    // search k inside a
    return _search(a, 0, a.length-1, k);
  }

}
