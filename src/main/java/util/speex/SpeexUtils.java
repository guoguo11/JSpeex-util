package util.speex;

import java.lang.reflect.Field;

/**
 * @author guoshuyun
 * 2017/7/26
 */
public class SpeexUtils {

    /**
     * .speex to .wav
     * @param src .speex文件路径
     * @param dist .wav文件路径
     * @return
     */
    public static native boolean decode(String src, String dist);

    static {
        try {

            System.setProperty("java.library.path", System.getProperty("java.library.path") + ":/usr/local/lib/");
            Field fieldSysPath = ClassLoader.class.getDeclaredField("sys_paths");
            fieldSysPath.setAccessible(true);
            fieldSysPath.set(null, null);
            System.loadLibrary("jspeex");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


}
