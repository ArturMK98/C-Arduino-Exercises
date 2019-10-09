/**
 * Student name: Artur Karolewski
 * Student number: 17388976
 * Question 1
 * 
 * This program generates random values for 4 variables p, q, r and s.
 * It prints out the values generated and then finds the absolute
 * difference of q and r, checks if the absolute difference of
 * p and r is greater than the value of q and finally finds the absolute
 * difference of the absolute difference of p and q and r and s.
 * 
 * There is a delay of 5 seconds after each loop.
 */

const int SUPERLOOP_MS = 5000;
int findDifference(int a, int b);

void setup() {
  Serial.begin(9600);
  Serial.println("------------ Lab4_PureFunction starting ----------");

}

void loop() {
  int difference;
  int p;
  int q;
  int r;
  int s;

  p = random(100);
  q = random(100);
  r = random(100);
  s = random(100);

  Serial.print("p is ");
  Serial.print(p);
  Serial.print(", ");
  Serial.print("q is ");
  Serial.print(q);
  Serial.print(", ");
  Serial.print("r is ");
  Serial.print(r);
  Serial.print(", ");
  Serial.print("s is ");
  Serial.print(s);
  Serial.println();

  Serial.print("abs diff q and r is ");
  difference = findDifference(q, r);
  Serial.print(difference);
  Serial.println();

  if (findDifference(p, r) > q){

      Serial.println("abs diff p and r > q is true");
    } else {

      Serial.println("abs diff p and r > q is false");
    }

  difference = findDifference(findDifference(p, q), findDifference(r, s));

  Serial.print("abs diff of abbs diff p and q and abs diff r and s is ");
  Serial.print(difference);
  Serial.println();
  Serial.println("--------");

  delay(SUPERLOOP_MS);

}

int findDifference(int x, int y){

  if (x > y){

    return x - y;
  }else{

    return y - x;
  }
}
