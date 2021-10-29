using System;
using System.Collections.Generic;
using System.Linq;
using System.Management.Instrumentation;
using System.Net.Configuration;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Example_Project
{
    struct CarStorage
    {
        public string make;
        public string model;
        public string modelNumber;
    }

    public class Car
    {
        private CarStorage cs;

        public Car(string make, string model, string modelNumber)
        {
            cs.make = make;
            cs.model = model;
            cs.modelNumber = modelNumber;
        }

        public string ModeSelecter(int currentMode)
        {
            if (currentMode == 0)
                return "Thanks for driving the " + cs.make + " " + cs.model + ".\nModel Number:" + cs.modelNumber;

            if (currentMode == 1)
                return "Welcome to your " + cs.make + " " + cs.model + ".\nModel Number:" + cs.modelNumber;

            return "Speed: 0MPH | Milage: 1200MI";
        }
    }
}
