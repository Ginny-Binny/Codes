import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/download")
public class FileDownloadServlet extends HttpServlet {
    private static final String UPLOAD_DIR = "uploads";

    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String fileName = request.getParameter("file");

        if (fileName == null || fileName.isEmpty()) {
            response.getWriter().println("Invalid file!");
            return;
        }

        String applicationPath = request.getServletContext().getRealPath("");
        String downloadPath = applicationPath + File.separator + UPLOAD_DIR + File.separator + fileName;
        File file = new File(downloadPath);
        if (!file.exists()) {
            response.getWriter().println("File not found!");
            return;
        }

        String mimeType = getServletContext().getMimeType(downloadPath);
        if (mimeType == null) {
            mimeType = "application/octet-stream";
        }

        response.setContentType(mimeType);
        response.setContentLength((int) file.length());
        response.setHeader("Content-Disposition", "attachment; filename=\"" + fileName + "\"");

        try (FileInputStream fileInputStream = new FileInputStream(file)) {
            int bytesRead;
            byte[] buffer = new byte[4096];

            while ((bytesRead = fileInputStream.read(buffer)) != -1) {
                response.getOutputStream().write(buffer, 0, bytesRead);
            }
        }
    }
}
