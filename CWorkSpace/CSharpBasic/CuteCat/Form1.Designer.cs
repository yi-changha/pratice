
namespace CuteCat
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.CatScreen = new System.Windows.Forms.Label();
            this.Play = new System.Windows.Forms.Button();
            this.Feed = new System.Windows.Forms.Button();
            this.CatTimer = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // CatScreen
            // 
            this.CatScreen.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.CatScreen.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.CatScreen.Location = new System.Drawing.Point(13, 13);
            this.CatScreen.Name = "CatScreen";
            this.CatScreen.Size = new System.Drawing.Size(258, 120);
            this.CatScreen.TabIndex = 0;
            this.CatScreen.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Play
            // 
            this.Play.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Play.Location = new System.Drawing.Point(13, 148);
            this.Play.Name = "Play";
            this.Play.Size = new System.Drawing.Size(120, 54);
            this.Play.TabIndex = 1;
            this.Play.Text = "Play";
            this.Play.UseVisualStyleBackColor = true;
            this.Play.Click += new System.EventHandler(this.Play_Click);
            // 
            // Feed
            // 
            this.Feed.Font = new System.Drawing.Font("맑은 고딕", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Feed.Location = new System.Drawing.Point(151, 148);
            this.Feed.Name = "Feed";
            this.Feed.Size = new System.Drawing.Size(120, 54);
            this.Feed.TabIndex = 2;
            this.Feed.Text = "Feed";
            this.Feed.UseVisualStyleBackColor = true;
            this.Feed.Click += new System.EventHandler(this.Feed_Click);
            // 
            // CatTimer
            // 
            this.CatTimer.Enabled = true;
            this.CatTimer.Interval = 5000;
            this.CatTimer.Tick += new System.EventHandler(this.CatTimer_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(288, 219);
            this.Controls.Add(this.Feed);
            this.Controls.Add(this.Play);
            this.Controls.Add(this.CatScreen);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label CatScreen;
        private System.Windows.Forms.Button Play;
        private System.Windows.Forms.Button Feed;
        private System.Windows.Forms.Timer CatTimer;
    }
}

