
namespace show_video
{
    public partial class MainWindow : Form
    {
        public MainWindow()
        {
            InitializeComponent();
            this.FormClosing += Stop_Click;
        }

        private void WebCamCapture_Click(object sender, EventArgs e)
        {
            if (null != m_draw)
            {
                m_draw.Close();
            }
            m_draw = new DrawVideoCLR(videoWindow.Handle);
            m_running = true;
            while (m_running)
            {
                m_draw.Draw();
            }
        }

        [STAThread]
        private void SelectVideoFile()
        {
            fileDialog = new OpenFileDialog();
            fileDialog.Filter = "Video Files (*.avi; *.mp4; *.wmv; *.mpg)|*.avi;*.mp4;*.wmv;*.mpg";
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                m_selectedFilePath = fileDialog.FileName;
            }
            else 
            {
                m_selectedFilePath = null;
            }

        }
        private void FileCapture_Click(object sender, EventArgs e)
        {
            Thread thread = new Thread(() => SelectVideoFile());
            thread.SetApartmentState(ApartmentState.STA);
            thread.Start();
            thread.Join();
            if (m_selectedFilePath != null) 
            {
                if (null != m_draw)
                {
                    m_draw.Close();
                }
                m_draw = new DrawVideoCLR(videoWindow.Handle,m_selectedFilePath);
                m_running = true;
                while(m_running) 
                {
                    m_draw.Draw();     
                }
            }  
        }

        private void Stop_Click(object sender, EventArgs e)
        {
            m_running =false;
            if (null != m_draw)
            {
                m_draw.Close();
                m_draw = null;
            }
        }

        private static DrawVideoCLR? m_draw;
        private volatile string m_selectedFilePath;
        private volatile bool m_running;
    }
}
