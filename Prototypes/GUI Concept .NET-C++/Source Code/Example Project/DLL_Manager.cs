using System;
using System.Runtime.InteropServices;

namespace Example_Project
{
    public static class DLL_Manager
    {
        // Imports the C++ Library from root
        [DllImport("DLL_Library", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr Helloworld();

        [DllImport("DLL_Library", CallingConvention = CallingConvention.Cdecl)]
        static public extern double Calculator(double x, double y, bool opt);
    }
}
