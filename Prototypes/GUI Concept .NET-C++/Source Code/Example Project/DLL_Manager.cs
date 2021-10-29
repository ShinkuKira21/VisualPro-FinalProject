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

        [DllImport("DLL_Library", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr InitialiseCar([MarshalAs(UnmanagedType.AnsiBStr)] string make,
            [MarshalAs(UnmanagedType.AnsiBStr)] string model, [MarshalAs(UnmanagedType.AnsiBStr)] string modelNumber);

        [DllImport("DLL_Library", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr Ignition(IntPtr car, int currentMode);

        [DllImport("DLL_Library", CallingConvention = CallingConvention.Cdecl)]
        static public extern void DeleteCPointer(IntPtr cPointer);

        [DllImport("DLL_Library", CallingConvention = CallingConvention.Cdecl)]
        static public extern void DisposeCar(IntPtr car);
    }
}