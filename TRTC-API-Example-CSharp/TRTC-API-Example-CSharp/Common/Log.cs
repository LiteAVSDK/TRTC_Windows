﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;
using System.Diagnostics;
using System.Reflection;

namespace TRTCCSharpDemo.Common
{
    class Log
    {
        private static TextWriter tWriter = null;  

        public static void Open()
        {
            try
            {
                string path = AppDomain.CurrentDomain.SetupInformation.ApplicationBase;
                path += "demolog\\";
                Directory.CreateDirectory(path);

                path += DateTime.Now.ToString("yyyy_MM_dd_HH_mm_ss_fff");
                path += ".log";
                // Wrapping with Synchronized prevents IO insecurity
                tWriter = TextWriter.Synchronized(new StreamWriter(path));  
                
            }
            catch (Exception e)
            {
                Debug.Assert(false);
                Console.WriteLine(e.ToString());
            }
        }

        public static void Close()
        {
            if (null != tWriter)
            {
                tWriter.Flush();
                tWriter.Close();

                tWriter = null;
            }
        }

        public static void I(string content)
        {
            string parentMethod = "";

            StackTrace stackTrace = new StackTrace(true);
            MethodBase methodBase = stackTrace.GetFrame(1).GetMethod();

            // Get the full name of the parent method class
            parentMethod += methodBase.DeclaringType.FullName;

            // Separator
            parentMethod += ".";

            // Get the parent method name
            parentMethod += methodBase.Name;

            write(parentMethod, content);
        }

        public static void E(string content)
        {
            string parentMethod = "";

            StackTrace stackTrace = new StackTrace(true);
            MethodBase methodBase = stackTrace.GetFrame(1).GetMethod();

            // Get the full name of the parent method class
            parentMethod += methodBase.DeclaringType.FullName;

            // Separator
            parentMethod += ".";

            // Get the parent method name
            parentMethod += methodBase.Name;

            write(parentMethod, content);
        }

        private static void write(string parentMethod, string content)
        {
            string msg = String.Format("[{0}][{1}], [{2}], [{3}]"
                , System.Threading.Thread.CurrentThread.ManagedThreadId
                , DateTime.Now.ToString("MM-dd HH:mm:ss.fff")
                , parentMethod
                , content);

            Console.WriteLine(msg);

            if (null != tWriter)
            {
                tWriter.WriteLine(msg);
            }
        }
    }
}
