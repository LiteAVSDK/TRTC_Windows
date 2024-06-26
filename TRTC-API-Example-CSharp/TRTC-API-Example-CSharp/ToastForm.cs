﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TRTCCSharpDemo
{
    public partial class ToastForm : Form
    {
        private System.Timers.Timer mTimer = null;

        public ToastForm()
        {
            InitializeComponent();

            this.Disposed += new EventHandler(OnDisposed);
            
            // Displayed in the top middle
            int x = (System.Windows.Forms.SystemInformation.WorkingArea.Width - this.ClientSize.Width) / 2;
            int y = 0;
            this.StartPosition = FormStartPosition.Manual; // Location of the form determined by the location attribute
            this.Location = (Point)new Size(x, y);         // The form starts at (x,y)

        }

        private void OnDisposed(object sender, EventArgs e)
        {
            //Resource cleaning
            if (mTimer != null)
            {
                mTimer.Stop();
            }
        }

        public void SetText(string text, int time = 0)
        {
            this.textLabel.Text = text;
            if (time != 0)
            {
                mTimer = new System.Timers.Timer(time);
                mTimer.Interval = time;
                mTimer.Elapsed += new System.Timers.ElapsedEventHandler(OnTimerEvent);
                mTimer.Start();
            }
        }

        private void OnTimerEvent(object sender, System.Timers.ElapsedEventArgs e)
        {
            this.BeginInvoke(new Action(() =>
            {
                this.DialogResult = DialogResult.Abort;
                mTimer.Stop();
                this.Hide();
            }));
        }

        public void SetPosition(int x, int y)
        {
            this.StartPosition = FormStartPosition.Manual; // Location of the form determined by the location attribute
            this.Location = (Point)new Size(x, y);         // The form starts at (x,y)
        }

        public void SetBackgroundColor(Color color)
        {
            this.BackColor = color;
        }

        public void SetTextColor(Color color)
        {
            this.textLabel.ForeColor = color;
        }
        
    }
}
