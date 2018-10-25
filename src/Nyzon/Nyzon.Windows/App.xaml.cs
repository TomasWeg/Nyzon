using Nyzon.Core.Logger;
using System.Windows;

namespace Nyzon.Windows
{
    /// <summary>
    /// Lógica de interacción para App.xaml
    /// </summary>
    public partial class App : Application
    {
        /// <summary>
        /// Application startup overriden
        /// </summary>
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);

            CoreLogger.Init();
        }

        /// <summary>
        /// Application exit overriden
        /// </summary>
        protected override void OnExit(ExitEventArgs e)
        {
            base.OnExit(e);

            CoreLogger.Terminate();
        }
    }
}
