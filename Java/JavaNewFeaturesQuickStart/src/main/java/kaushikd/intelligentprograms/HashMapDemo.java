package kaushikd.intelligentprograms;

import java.util.HashMap;
import java.util.Map;

public class HashMapDemo {
    public static void main(String[] args) {
        HashMap<String, Integer> hm = new HashMap<>();

        hm.put("kaushik", "kaushik".length());
        System.out.println(hm.get("kaushik"));
        hm.compute("kaushik", (k, v) -> { return v + v; });
        System.out.println(hm.get("kaushik"));
        hm.put("kaushik", "kaushik".length());
        System.out.println(hm.get("kaushik"));
        hm.compute("unknown", (k, v) -> { return -1; });
        hm.compute("un", (k, v) -> { return v; });
        hm.computeIfAbsent("pratima", k -> k.length());
        System.out.println(hm.get("unknown"));
        System.out.println(hm.get("un"));
        System.out.println(hm.containsKey("unknown"));
        System.out.println(hm.containsKey("un"));

        for (Map.Entry<String, Integer> e : hm.entrySet()) {
            System.out.println(e);
        }
    }
}
