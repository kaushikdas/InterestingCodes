import java.io.IOException;
import com.github.lalyos.jfiglet.FigletFont;

public class GreeterApp {
    public static void main(String[] args) throws IOException {
        String asciiArt = FigletFont.convertOneLine("Hello, " + args[0]);
        System.out.println(asciiArt);
    }
}

/*
 * ❯ ./gradlew build
 * ❯ ./gradlew run --args=Kaushik
 *
 *  > Task :run
 *  _   _          _   _                 _  __                        _       _   _
 * | | | |   ___  | | | |   ___         | |/ /   __ _   _   _   ___  | |__   (_) | | __
 * | |_| |  / _ \ | | | |  / _ \        | ' /   / _` | | | | | / __| | '_ \  | | | |/ /
 * |  _  | |  __/ | | | | | (_) |  _    | . \  | (_| | | |_| | \__ \ | | | | | | |   <
 * |_| |_|  \___| |_| |_|  \___/  ( )   |_|\_\  \__,_|  \__,_| |___/ |_| |_| |_| |_|\_\
 *                                |/
 *
 *
 * BUILD SUCCESSFUL in 1s
 * 2 actionable tasks: 1 executed, 1 up-to-date*/
* ❯ 
*/