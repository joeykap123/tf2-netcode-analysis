using System;
using System.IO;
using System.Collections.Generic;

    public class Program
    {

        public static void main(string args[])
            {
                if (args.Length == 0)
                {
                    Console.WriteLine("Error: Path argument needed
                    ");
                    return;
                }

                var path = arg[0];
                if (!File.Exists(path))
                {
                    Console.WriteLine($"File Not Found: {path}");
                    return;
                }

                parse(path);
            }
    }



    private static parse(File file)
    {
       // Attempt to deserialize JSON data
       var json = File.ReadAllText(file);
        //TODO:: Finish implementation
    }


    //TODO
    class math 
    {
        public static randomizePacketLoss(Player plyr)
        {

        }


        /// <summary>
        /// This method simulates latency.
        /// </summary>
        public static randomizeLatency(Player plyr)
        {
            Random rand = new Random();
            rand.Next(3, 200);
        }

        /// <summary>
        /// This method simulates latency that makes a game unplayable.
        /// </summary>
        public static randomizeLatencyUpperBound(Player plyr)
        {
             Random rand = new Random();
            rand.Next(100, 1000);
        }

        public static randomizeJitter(Player plyr) 
        {
          
        }

    
        
        public static randomizeJitterExtreme(Player plyr)
        {
           
        }


        public static Position LinearInterp()
        {
            
        }

        public static Position CubicHermiteInterp()
        {
            
        }

        
    }
    
    
    /// <summary>
    /// Class SimulationParameters represents our JSON objects.
    /// </summary>
    public class SimulationParameters
    {
        public int TickRate { get; set; }
        public int InterpolationDelayMs { get; set; }
        public double PacketLossPercent { get; set; }
        public int LatencyMs { get; set; }
        public int NumPlayers { get; set; }
        public int DurationSeconds { get; set; }
    }

    public class Position 
    {
        [JSONPropertyName("tickRate")]
        public int TickRate {get; set;}
        public double x {get;set;};
        public double y {get;set;};
        public double z {get;set;};

    }

    public class Player
    {
        public String username {get;set;};
        public List<Position>() posList {get;set;}= new List<Position>();
    }

    public class SimData 
    {
        public SimulationParameters simParams {get;set;};
        public List<Players>() playerList {get;set;} = new List<Players>();
    }
