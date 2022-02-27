
using System;
using System.Runtime.InteropServices;

namespace VP_Comms
{
    public static class List
    {
        [DllImport("List.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr InitialiseClass([MarshalAs(UnmanagedType.AnsiBStr)] string strInp);

        [DllImport("List.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern void DisposeClass(IntPtr obj);

        [DllImport("List.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr CallFunction(IntPtr obj, [MarshalAs(UnmanagedType.AnsiBStr)] string strInp, [MarshalAs(UnmanagedType.AnsiBStr)] string name, [MarshalAs(UnmanagedType.AnsiBStr)] string parent, int id);
    }

    public static class ProgrammingPlanner
    {
        [DllImport("Manager.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr InitialiseClass(IntPtr ts, [MarshalAs(UnmanagedType.AnsiBStr)] string strInp);

        [DllImport("Manager.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern void DisposeClass(IntPtr obj);

        [DllImport("Manager.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern void CallFunction(IntPtr obj, [MarshalAs(UnmanagedType.AnsiBStr)] string strInp, [MarshalAs(UnmanagedType.AnsiBStr)] string member, [MarshalAs(UnmanagedType.AnsiBStr)] string dataType, [MarshalAs(UnmanagedType.AnsiBStr)] string name, [MarshalAs(UnmanagedType.AnsiBStr)] string parent, int id);

        [DllImport("Manager.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr CallStringFunction(IntPtr obj, IntPtr ts, [MarshalAs(UnmanagedType.AnsiBStr)] string strInp);
    }

    public static class Decoder
    {
        // Group Programming Planner Lists

        // Initializes Planner Class
        [DllImport("Decoder.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr InitialisePlannerClass();

        // Add Programming Planner to Plan
        [DllImport("Decoder.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern void AddPlan(IntPtr memory, IntPtr programmingPlanner);

        // Dispose Planner Class
        [DllImport("Decoder.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern void DisposePlannerClass(IntPtr memory);

        // Configures Language Compiler
        [DllImport("Decoder.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr InitialiseXMLClass([MarshalAs(UnmanagedType.AnsiBStr)] string xmlDir, [MarshalAs(UnmanagedType.AnsiBStr)] string xmlFile, bool debug = false);

        // Dispose Language Compiler
        [DllImport("Decoder.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern void DisposeXMLClass(IntPtr xml);

        // Calls the language compiler
        [DllImport("Decoder.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr CompileLanguage(IntPtr memory, IntPtr ts, IntPtr xmlDoc, [MarshalAs(UnmanagedType.AnsiBStr)] string language, [MarshalAs(UnmanagedType.AnsiBStr)] string libraries, [MarshalAs(UnmanagedType.AnsiBStr)] string syntax);

        [DllImport("Decoder.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr SendCommand(IntPtr ts, IntPtr xmlDoc, [MarshalAs(UnmanagedType.AnsiBStr)] string command, [MarshalAs(UnmanagedType.AnsiBStr)] string language = "");

    }

    public static class Libraries
    {
        [DllImport("Libraries.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr InitialiseTS();

        [DllImport("Libraries.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern void DisposeTS(IntPtr ts);

        [DllImport("Libraries.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr FindSubStr(IntPtr ts, [MarshalAs(UnmanagedType.AnsiBStr)] string str, int pos, char seperator);

        [DllImport("Libraries.dll", CallingConvention = CallingConvention.Cdecl)]
        static public extern IntPtr FileController([MarshalAs(UnmanagedType.AnsiBStr)] string command, [MarshalAs(UnmanagedType.AnsiBStr)] string data,
            [MarshalAs(UnmanagedType.AnsiBStr)] string fileDirectory);
    }
}