package kaushikd.java.exps;

import lombok.NoArgsConstructor;
import lombok.ToString;
import lombok.extern.slf4j.Slf4j;
//import org.slf4j.Logger;
//import org.slf4j.LoggerFactory;

@NoArgsConstructor
@ToString
@Slf4j
public class GaussianRandom {
    public static void main(String[] args) {
        //Logger logger = LoggerFactory.getLogger(GaussianRandom.class);

        log.info("GaussianRandom Class");
        double u = Math.random();
        double v = Math.random();

        double r = Math.sin(2*Math.PI*v)*Math.sqrt(-2*Math.log(u));
        log.info("Random number: " + r);
    }
}