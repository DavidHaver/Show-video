namespace show_video
{
    partial class MainWindow
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            WebCamCapture = new Button();
            Stop = new Button();
            FileCapture = new Button();
            videoWindow = new PictureBox();
            fileDialog = new OpenFileDialog();
            ((System.ComponentModel.ISupportInitialize)videoWindow).BeginInit();
            SuspendLayout();
            // 
            // WebCamCapture
            // 
            WebCamCapture.Anchor = AnchorStyles.Bottom;
            WebCamCapture.Location = new Point(484, 652);
            WebCamCapture.Name = "WebCamCapture";
            WebCamCapture.Size = new Size(104, 52);
            WebCamCapture.TabIndex = 0;
            WebCamCapture.Text = "Start Capture From WebCam";
            WebCamCapture.UseVisualStyleBackColor = true;
            WebCamCapture.Click += WebCamCapture_Click;
            // 
            // Stop
            // 
            Stop.Anchor = AnchorStyles.Bottom;
            Stop.Location = new Point(827, 652);
            Stop.Name = "Stop";
            Stop.Size = new Size(104, 52);
            Stop.TabIndex = 1;
            Stop.Text = "Stop";
            Stop.UseVisualStyleBackColor = true;
            Stop.Click += Stop_Click;
            // 
            // FileCapture
            // 
            FileCapture.Anchor = AnchorStyles.Bottom;
            FileCapture.Location = new Point(649, 652);
            FileCapture.Name = "FileCapture";
            FileCapture.Size = new Size(104, 52);
            FileCapture.TabIndex = 2;
            FileCapture.Text = "Start Capture From File";
            FileCapture.UseVisualStyleBackColor = true;
            FileCapture.Click += FileCapture_Click;
            // 
            // videoWindow
            // 
            videoWindow.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            videoWindow.Location = new Point(0, -3);
            videoWindow.Name = "videoWindow";
            videoWindow.Size = new Size(1498, 649);
            videoWindow.TabIndex = 3;
            videoWindow.TabStop = false;
            // 
            // fileDialog
            // 
            fileDialog.FileName = "fileDialog";
            // 
            // MainWindow
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1498, 744);
            Controls.Add(videoWindow);
            Controls.Add(FileCapture);
            Controls.Add(Stop);
            Controls.Add(WebCamCapture);
            Name = "MainWindow";
            Text = "MainWindow";
            ((System.ComponentModel.ISupportInitialize)videoWindow).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private Button WebCamCapture;
        private Button Stop;
        private Button FileCapture;
        private PictureBox videoWindow;
        private OpenFileDialog fileDialog;
    }
}
