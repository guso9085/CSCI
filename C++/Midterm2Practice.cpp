/*
   EXAMPLE 1  // Normal Classes
   class Star {
    public:
        Star () {
          name = '';
          mass = 0.0;
          radius = 0.0;
        }
        Star (string a, float b, float c){
          name = a;
          mass = b;
          radius = c;

        }

    private:
        string name;
        float mass;
        float radius;
    };

   EXAMPLE 2  // Normal Classes
    class Meme {
      private:
        string name;
        float rating;
        int dankness;
      public:
          Meme () {
            name = "";
            rating = 0.0;
            dankness = 0;
        }
          Meme (string a, float b, int c){
            name = a;
            rating = b;
            dankness = c;
        }
    }

   EXAMPLE 3     // GETTERS AND SETTERS
   class Meme {
    private:
      string name;
      float rating;
      int dankness;
    public:
        Meme () {
          name = "";
          rating = 0.0;
          dankness = 0;
        }
        Meme (string a, float b, int c){
          name = a;
          rating = b;
          dankness = c;
        }

        void Set_name(string a){
          name = a;
      }
        string Get_name(){
          return  name;
      }
   }

 */
