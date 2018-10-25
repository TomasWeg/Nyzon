using System.IO;
using System;

namespace Nyzon.Core.Logger
{
    /// <summary>
    /// Base class to create a new buffer for the <see cref="Console"/>
    /// so by that way, we can retrieve the information we log to the console
    /// </summary>
    public static class CoreLogger
    {
        #region Private Members

        /// <summary>
        /// The new buffer of the console
        /// </summary>
        private static StringWriter mBuffer;

        /// <summary>
        /// Indicates if the logger was initialized
        /// </summary>
        private static bool mInitialized;

        #endregion

        #region Methods

        /// <summary>
        /// Initializes the logger.
        /// This action must be called at the startup of the GUI application 
        /// and will return TRUE if the action success
        /// </summary>
        public static bool Init()
        {
            // Return false if the logger was already initialized
            if (mInitialized)
                return false;

            // Create buffer for the console
            mBuffer = new StringWriter();

            // Set the console buffer to the new
            Console.SetOut(mBuffer);

            // Mark as initialized
            mInitialized = true;

            // Return sucess
            return true;
        }

        /// <summary>
        /// Terminates the logger.
        /// This action must be called just before the GUI application exists.
        /// </summary>
        public static void Terminate()
        {
            // If the logger was not initialized, just return
            if (!mInitialized)
                return;

            // Close and dispose console buffer 
            mBuffer.Close();
            mBuffer.Dispose();
        }

        /// <summary>
        /// Reads the information allocated on the new console buffer
        /// </summary>
        public static string ReadBuffer()
        {
            return mBuffer.ToString();
        }

        #endregion
    }
}
