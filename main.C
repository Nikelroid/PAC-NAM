
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int enemy_num,enemy_i,enemy_j,level=1;
int play_ground[20][20];


void printmoves(int move){
    char moves[50];
            snprintf(moves, 20, "moves: %d", move);

        outtextxy(290, 265, moves);
}
void settingcolor(int i,int j){

 switch (play_ground[i][j]) {
                                case 41:
                                    setcolor(LIGHTRED);
                                    break;
                                case 42:
                                    setcolor(LIGHTMAGENTA);
                                    break;
                                case 43:
                                    setcolor(LIGHTCYAN);
                                    break;
                                case 44:
                                    setcolor(LIGHTGRAY);
                                    break;
                                case 51:
                                    setcolor(LIGHTRED);
                                    break;
                                case 52:
                                    setcolor(LIGHTMAGENTA);
                                    break;
                                case 53:
                                    setcolor(LIGHTCYAN);
                                    break;
                                case 54:
                                    setcolor(LIGHTGRAY);
                                    break;
                            }
}


void play_change(){
    int j,k,i;
     for (j=0;j<20;++j){
                 for (k=0;k<20;++k){
             if (play_ground[j][k]<0) {
                         play_ground[j][k]*= (-1);
                if(play_ground[j][k]>50){
                        setcolor(YELLOW);
                    for(i=9;i<11;i++)
                    circle(30+(20*j),30+(20*k),i);
                }
                 }
            }
     }

}

void entering (int num[4]){
 setcolor(BLACK);
 int i;
            for (i = 0; i < 105; i++) {
                rectangle(535 - i, 145 - i, 535 + i, 145 + i);;
            }
                if (enemy_num <= 3 && play_ground[enemy_i][enemy_j]<21 && play_ground[enemy_i][enemy_j]!=0 ) {
            switch (num[enemy_num]) {
                case 41:
                    setcolor(LIGHTRED);
                    outtextxy(450, 60, "Blinky Entered Game");
                    Beep(1200,200);
                    break;
                case 42:
                    setcolor(LIGHTMAGENTA);
                    outtextxy(450, 60, "Pinky Entered Game");
                      Beep(1200,200);
                    break;
                case 43:
                    setcolor(LIGHTCYAN);
                    outtextxy(450, 60, "Inky Entered Game");
                      Beep(1200,200);
                    break;
                case 44:
                    setcolor(LIGHTGRAY);
                    outtextxy(450, 60, "Clyde Entered Game");
                      Beep(1200,200);
                    break;
            }
             for (i = 0; i < 3; i++) {
                circle(34 + (20 * enemy_i), 23 + (20 * enemy_j), i);
                circle(26 + (20 * enemy_i), 23 + (20 * enemy_j), i);
            }
            outtextxy(23 + (20 * enemy_i), 25 + (20 * enemy_j), "W");
            play_ground[enemy_i][enemy_j] = num[enemy_num];
            enemy_num++;
        }
                return;
}


struct Point
{
	int x;
	int y;
};

struct queueNode
{
	Point pt;
	int dist;
};

bool isValid(int e_i, int e_j)
{
	return (e_i >= 0) && (e_i < 20) &&
		(e_j >= 0) && (e_j < 20);
}
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int Pathfinding(int pg[][20], Point src, Point dest)
{

	if (!pg[src.x][src.y] || !pg[dest.x][dest.y])
		return -1;

	bool visited[20][20];
	memset(visited, false, sizeof visited);

	visited[src.x][src.y] = true;

	queue<queueNode> q;

	queueNode s = {src, 0};
	q.push(s);

	while (!q.empty())
	{
		queueNode curr = q.front();
		Point pt = curr.pt;

		if (pt.x == dest.x && pt.y == dest.y)

			return curr.dist;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int e_i = pt.x + rowNum[i];
			int e_j = pt.y + colNum[i];
			if (isValid(e_i, e_j) && pg[e_i][e_j] &&
			!visited[e_i][e_j])
			{

				visited[e_i][e_j] = true;
				queueNode Adjcell = { {e_i, e_j},
									curr.dist + 1 };

				q.push(Adjcell);


			}
		}
	}
	return -1;
}

int moveing(int player_i,int player_j,int enemy_i,int enemy_j){
    int distance[4],i,j,k;
    int maze[20][20];
if (level==1){
srand(time(NULL));
return (rand()%4 +1);
}else if(level==2){
    distance[0] = ((player_i-(enemy_i+1))*(player_i-(enemy_i+1)))+((player_j-(enemy_j))*(player_j-(enemy_j)));
    distance[1] = ((player_i-(enemy_i-1))*(player_i-(enemy_i-1)))+((player_j-(enemy_j))*(player_j-(enemy_j)));
    distance[2] = ((player_i-(enemy_i))*(player_i-(enemy_i)))+((player_j-(enemy_j-1))*(player_j-(enemy_j-1)));
    distance[3] = ((player_i-(enemy_i))*(player_i-(enemy_i)))+((player_j-(enemy_j+1))*(player_j-(enemy_j+1)));
    if(distance[0]<=distance[1] && distance[0]<=distance[2] && distance[0]<=distance[3] ){
        return 1;
    }else if(distance[1]<=distance[0] && distance[1]<=distance[2] && distance[1]<=distance[3]){
        return 2;
    }else if(distance[2]<=distance[1] && distance[2]<=distance[0] && distance[2]<=distance[3] ){
        return 3;
    }else if(distance[3]<=distance[1] && distance[3]<=distance[2] && distance[3]<=distance[0] ){
            return 4;
    }
    }else if(level==3){



        int temp[20][20];
          for(i=0;i<20;i++){
         for(j=0;j<20;j++){
                temp[j][i]=play_ground[i][j];
         }
          }


   for(i=0;i<20;i++){
         for(j=0;j<20;j++){
        if (temp[i][j] == 1 || temp[i][j] == 2 || temp[i][j] == 4){
            temp[i][j] = 1;
        }else if(temp[i][j] >= 30 || temp[i][j] <= 43) {
            temp[i][j] = 0;
        }
        }
    }

	Point source = {player_j, player_i};

        int right = Pathfinding(temp, source, { enemy_j,enemy_i+1});
        int left = Pathfinding(temp, source, {enemy_j, enemy_i-1});
        int up = Pathfinding(temp, source, {enemy_j-1,enemy_i});
        int down = Pathfinding(temp, source, {enemy_j+1,enemy_i });

        if (right==-1)right =400;
        if (left==-1)left =400;
        if (up==-1)up =400;
        if (down==-1)down =400;
		if (right<=left && right<=up && right<=down ){
            return 1;
		}else if (left<=right && left<=down && left<=up ){
            return 2;
		}else if (up<=left && up<=right && up<=down ){
            return 3;
		}else if (down<=up && down<=left && down<=right ){
            return 4;
		}
        }
    }

int enemy_cio(int j,int k,int player_i,int player_j){
    int movement,q,i;
    movement=moveing(player_i,player_j,j,k);
                        if(movement==1 && play_ground[j+1][k] < 11 && play_ground[j+1][k] != 0){
                                 setcolor(BLACK);

                    if (play_ground[j][k]>50)
                    for(i=9;i<11;i++)
                    circle(30+(20*j),30+(20*k),i);

                        for (q = 0; q < 20; q++) {
                            setcolor(BLACK);
                            for (i = 0; i < 3; i++) {
                                circle(34 + (20 * j)+q, 23 + (20 * k) , i);
                                circle(26 + (20 * j)+q, 23 + (20 * k) , i);
                            }
                            outtextxy(23 + (20 * j)+q, 25 + (20 * k) , "W");
                            setcolor(YELLOW);
                            if (play_ground[j][k]>50)
                            for (i = 0; i < 8; i++)
                            circle((30 + (20 * j)), (30 + (20 * k)), i);
                           settingcolor(j,k);
                            for (i = 0; i < 3; i++) {
                                circle(35 + (20 * j)+q, 23 + (20 * k) , i);
                                circle(27 + (20 * j)+q, 23 + (20 * k), i);
                            }
                            outtextxy(24 + (20 * j)+q, 25 + (20 * k) , "W");

                            delay(1);
                        }
                        if (play_ground[j][k]>45 && play_ground[j][k]<60){


                             if (play_ground[j+1][k]==2){
                            play_ground[j+1][k] = -play_ground[j][k];
                            play_ground[j][k] = 2;

                        }else{
                        play_ground[j+1][k] = -play_ground[j][k]+10;
                        play_ground[j][k] = 2;
                        }
                        }else{

                           if (play_ground[j+1][k]==2){
                            play_ground[j+1][k] = -play_ground[j][k]-10;
                            play_ground[j][k] = 1;
                        }else{
                        play_ground[j+1][k] = -play_ground[j][k];
                        play_ground[j][k] = 1;
                        }

                        }

                        return 0;
                        }else if(movement==2 && play_ground[j-1][k] < 21 && play_ground[j-1][k] != 0){
                                 setcolor(BLACK);
                                 if (play_ground[j][k]>50)
                    for(i=9;i<11;i++)
                    circle(30+(20*j),30+(20*k),i);
                        for (q = 0; q < 20; q++) {
                            setcolor(BLACK);
                            for (i = 0; i < 3; i++) {
                                circle(34 + (20 * j)-q, 23 + (20 * k) , i);
                                circle(26 + (20 * j)-q, 23 + (20 * k) , i);
                            }
                            outtextxy(23 + (20 * j)-q, 25 + (20 * k) , "W");
                            setcolor(YELLOW);
                            if (play_ground[j][k]>50)
                            for (i = 0; i < 8; i++)
                            circle((30 + (20 * j)), (30 + (20 * k)), i);
                            settingcolor(j,k);
                            for (i = 0; i < 3; i++) {
                                circle(33 + (20 * j)-q, 23 + (20 * k) , i);
                                circle(25 + (20 * j)-q, 23 + (20 * k), i);
                            }
                            outtextxy(22 + (20 * j)-q, 25 + (20 * k) , "W");

                            delay(1);
                        }

                    if (play_ground[j][k]>50 && play_ground[j][k]<55){
                           if (play_ground[j-1][k]==2){
                            play_ground[j-1][k] = -play_ground[j][k];
                            play_ground[j][k] = 2;
                        }else{
                       play_ground[j-1][k] = -play_ground[j][k]+10;
                        play_ground[j][k] = 2;
                        }



                        }else{

                           if (play_ground[j-1][k]==2){
                            play_ground[j-1][k] = -play_ground[j][k]-10;
                            play_ground[j][k] = 1;
                        }else{
                        play_ground[j-1][k] = -play_ground[j][k];
                        play_ground[j][k] = 1;
                        }

                        }
                        return 0;
                        }else if(movement==3 && play_ground[j][k - 1] < 21 && play_ground[j][k - 1] != 0){
                             setcolor(BLACK);
                             if (play_ground[j][k]>50)
                    for(i=9;i<11;i++)
                    circle(30+(20*j),30+(20*k),i);

                        for (q = 0; q < 20; q++) {
                            setcolor(BLACK);
                            for (i = 0; i < 3; i++) {
                                circle(34 + (20 * j), 23 + (20 * k) - q, i);
                                circle(26 + (20 * j), 23 + (20 * k) - q, i);
                            }
                            outtextxy(23 + (20 * j), 25 + (20 * k) - q, "W");

                            setcolor(YELLOW);
                            if (play_ground[j][k]>50)
                            for (i = 0; i < 8; i++)
                            circle((30 + (20 * j)), (30 + (20 * k)), i);


                            settingcolor(j,k);
                            for (i = 0; i < 3; i++) {
                                circle(34 + (20 * j), 22 + (20 * k) - q, i);
                                circle(26 + (20 * j), 22 + (20 * k) - q, i);
                            }
                            outtextxy(23 + (20 * j), 24 + (20 * k) - q, "W");

                            delay(1);
                        }

                         if (play_ground[j][k]>50 && play_ground[j][k]<55){

                        if (play_ground[j][k - 1]==2){
                            play_ground[j][k - 1] = -play_ground[j][k];
                            play_ground[j][k] = 2;
                        }else{

                       play_ground[j][k - 1] = -play_ground[j][k]+10;
                        play_ground[j][k] = 2;
                        }



                        }else if(play_ground[j][k]>40 && play_ground[j][k]<45){


                           if (play_ground[j][k - 1]==2){

                            play_ground[j][k - 1] = -play_ground[j][k]-10;
                            play_ground[j][k] = 1;
                        }else{

                        play_ground[j][k - 1] = -play_ground[j][k];
                        play_ground[j][k] = 1;
                        }

                        }

                        return 0;
                        }else if(movement==4 && play_ground[j][k + 1] < 21 && play_ground[j][k + 1] != 0){
                               setcolor(BLACK);
                               if (play_ground[j][k]>50)
                    for(i=9;i<11;i++)
                    circle(30+(20*j),30+(20*k),i);

                        for (q = 0; q < 20; q++) {
                            setcolor(BLACK);
                            for (i = 0; i < 3; i++) {
                                circle(34 + (20 * j), 23 + (20 * k) + q, i);
                                circle(26 + (20 * j), 23 + (20 * k) + q, i);
                            }
                            outtextxy(23 + (20 * j), 25 + (20 * k) + q, "W");
                            setcolor(YELLOW);
                            if (play_ground[j][k]>50)
                            for (i = 0; i < 8; i++)
                            circle((30 + (20 * j)), (30 + (20 * k)), i);
                           settingcolor(j,k);
                            for (i = 0; i < 3; i++) {
                                circle(34 + (20 * j), 24 + (20 * k) + q, i);
                                circle(26 + (20 * j), 24 + (20 * k) + q, i);
                            }
                            outtextxy(23 + (20 * j), 26 + (20 * k) + q, "W");

                            delay(1);
                        }
                         if (play_ground[j][k]>50 && play_ground[j][k]<55){
                        if (play_ground[j][k + 1]==2){
                            play_ground[j][k + 1] = -play_ground[j][k];
                            play_ground[j][k] = 2;
                        }else{
                       play_ground[j][k + 1] = -play_ground[j][k]+10;
                        play_ground[j][k] = 2;
                        }



                        }else{

                           if (play_ground[j][k + 1]==2){
                            play_ground[j][k + 1] = -play_ground[j][k]-10;
                            play_ground[j][k] = 1;
                        }else{
                        play_ground[j][k + 1] = -play_ground[j][k];
                        play_ground[j][k] = 1;
                        }

                        }
                        return 0;
                        }else{
                        return 1;
                        }
}

void looper(int p_i,int p_j){
int k,j,i,j1,k1,els=0;

 for (k=0; k < 20; ++k) {
                for (j=0 ; j < 20; ++j) {
                    if (play_ground[j][k] > 40 && play_ground[j][k]<60) {

                        if(enemy_cio(j,k,p_i,p_j)==1){
                                els++;
                        for (k1 = 19; k1 >= 0; --k1) {
                for (j1 = 19; j1 >= 0;--j1) {
                         if (play_ground[j1][k1] > 40 && play_ground[j1][k1]<60) {
                        enemy_cio(j1,k1,p_i,p_j);
                         }
                }
                        }
                        if (els<=400){
            k=0;
            j=0;
                        }
                        }else{

                        }
                    }
                }
            }

}
int coinprnt(int play_ground[20][20], int pi, int pj, int coin) {
    char score[20];

    if (play_ground[pi][pj] == 2) {
        coin += 1;
        snprintf(score, 20, "Your score: %d", coin);
        outtextxy(450, 20, score);
        return coin;
    } else if (pi == -1 && pj == -1) {
        snprintf(score, 20, "Your score: %d!", coin);
        outtextxy(278, 243, score);
    } else {
        return -33;
    }
}

void coins(int play_ground[20][20]) {

    int i, j, k;
    int x1 = 20, y1 = 20;
    for (k = 0; k < x1; ++k) {
        for (j = 0; j < y1; ++j) {
            if (play_ground[j][k] == 2) {
                setcolor(BLACK);
                for (i = 0; i < 8; i++) {
                    circle((30 + (20 * j)), (30 + (20 * k)), i);

                }
            }
        }
    }
    delay(50);
    for (k = 0; k < x1; ++k) {
        for (j = 0; j < y1; ++j) {
            if (play_ground[j][k] == 2) {
                setcolor(YELLOW);
                for (i = 0; i < 8; i++) {
                    circle((30 + (20 * j)), (30 + (20 * k)), i);
                }
            }
        }
    }

}

int main(void) {
    int c;
    level=1;
    int input,len = 4, m, r, temp,moves=0;
    int num[4];
    enemy_num=0;
    int coin = 0, coin_num = 0,movement=0,els=0;
    int gdriver = DETECT, gmode;
    int player_i, player_j;
    int i, j, k, col = 0, q ,j1,k1;
    int x1 = 20, y1 = 20;

    FILE *fp;
    char buff[1000];

    fp = fopen("E://play_ground.txt", "r");
 initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");



        int p = 0;
        for (i = 10000; i < 100000; i++) {
            putpixel(320 + ((i / 100) * cos(p)), 240 + ((i / 100) * sin(p)), i%16);
            p++;
        }
        setcolor(WHITE);
        outtextxy(250, 210, "Welcome to PAC-MAN!");
         Beep(250,500);
        outtextxy(250, 230, "   BY NIMA KELIDARI ");
         Beep(500,500);
        outtextxy(275, 250, "SN : 98108124");
        for (i=1;i<6;i++)
            Beep(300+350*i,200+150*i);
         cleardevice();

    for (j = 0; j < 20; ++j) {
        for (i = 0; i < 20; ++i) {
            fscanf(fp, "%s", buff);
            play_ground[i][j] = *buff;
        }
    }


    for (j = 0; j < 20; ++j) {
        for (i = 0; i < 20; ++i) {
            play_ground[i][j] -= 48;
        }
    }
    j = 0, k = 0;

    for (k = 0; k < x1; ++k) {
        for (j = 0; j < y1; ++j) {
            setcolor(WHITE);
            if (play_ground[j][k] == 0) {
                for (i = 0; i < 10; i++) {
                    rectangle((30 + (20 * j)) - i, (30 + (20 * k)) - i, (30 + (20 * j)) + i, (30 + (20 * k)) + i);
                }
            } else if (play_ground[j][k] == 2) {
                setcolor(YELLOW);
                for (i = 0; i < 8; i++) {
                    circle((30 + (20 * j)), (30 + (20 * k)), i);
                }
                coin_num++;

            } else if (play_ground[j][k] == 4) {
                player_i = j;
                player_j = k;
                play_ground[j][k] =1;
                setcolor(LIGHTGREEN);
                for (i = 0; i < 10; i++) {
                    arc(30 + (20 * j), 30 + (20 * k), 30, 330, i);

                }
                setcolor(BLACK);
                for (i = 0; i < 3; i++) {
                    circle(30 + (20 * j), 25 + (20 * k), i);

                }
            } else if (play_ground[j][k] == 3) {
                enemy_i = j;
                enemy_j = k;
                play_ground[enemy_i][enemy_j]=1;
            }
        }
    }
    outtextxy(450, 20, "insert your level:");
     outtextxy(450, 35, "1-Easy");
     outtextxy(450, 50, "2-Medium");
     outtextxy(450, 65, "3-Hard");
            switch(getch()){
            case 49 : level = 1;break;
            case 50 : level = 2;break;
            case 51 : level = 3;break;
            }

        setcolor(BLACK);
        for (i = 0; i < 105; i++) {
            rectangle(535 - i, 105 - i, 535 + i, 105 + i);;
        }

    for (temp = 0, m = 41; temp < len; m++, temp++)
        num[temp] = m;
    srand(time(NULL));
    for (m = len - 1; m > 0; m--) {
        r = rand() % m;
        temp = num[m];
        num[m] = num[r];
        num[r] = temp;
    }
        setcolor(WHITE);
        outtextxy(450, 20, "Your score: 0");
    while (play_ground[player_i][player_j] < 20 && coin_num != coin) {
        coins(play_ground);
        input = getch();
         switch((c=getch())) {
        case KEY_RIGHT:
        moves++;
            if (play_ground[player_i + 1][player_j] == 0) {
                setcolor(WHITE);
                outtextxy(450, 40, "No move!");
                Beep(800,150);
            } else {
                Beep(200,150);
                setcolor(BLACK);
                for (i = 0; i < 10; i++) {
                    circle(30 + (20 * player_i), 30 + (20 * player_j), i);

                }
                for (q = 0; q < 20; q++) {
                    setcolor(BLACK);
                    for (i = 0; i < 10; i++) {
                        arc(30 + q + (20 * player_i), 30 + (20 * player_j), 30, -30, i);
                    }
                    setcolor(LIGHTGREEN);
                    for (i = 0; i < 10; i++) {
                        arc(31 + q + (20 * player_i), 30 + (20 * player_j), 30, -30, i);
                    }
                    setcolor(BLACK);
                    for (i = 0; i < 3; i++) {
                        circle(31 + q + (20 * player_i), 25 + (20 * player_j), i);

                    }
                    delay(1);
                }

                player_i++;
                setcolor(WHITE);
                if (coinprnt(play_ground, player_i, player_j, coin) != -33) {
                    coin = coinprnt(play_ground, player_i, player_j, coin);
                     Beep(1500,300);
                    play_ground[player_i][player_j] = 1;
                }
            }
if (play_ground[player_i][player_j]<=40)
    looper(player_i,player_j);
            entering(num);
            play_change();
        ;break;
        case KEY_LEFT:

            moves++;
            if (play_ground[player_i - 1][player_j] == 0) {
                setcolor(WHITE);
                outtextxy(450, 40, "No move!");
            Beep(800,150);
            } else {
                Beep(200,150);
                setcolor(BLACK);
                for (i = 0; i < 10; i++) {
                    circle(30 + (20 * player_i), 30 + (20 * player_j), i);

                }
                for (q = 0; q < 20; q++) {
                    setcolor(BLACK);
                    for (i = 0; i < 10; i++) {
                        arc(30 - q + (20 * player_i), 30 + (20 * player_j), -150, 150, i);

                    }
                    setcolor(LIGHTGREEN);
                    for (i = 0; i < 10; i++) {
                        arc(29 - q + (20 * player_i), 30 + (20 * player_j), -150, 150, i);
                    }
                    setcolor(BLACK);
                    for (i = 0; i < 3; i++) {
                        circle(29 - q + (20 * player_i), 25 + (20 * player_j), i);

                    }
                    delay(1);
                }

                player_i--;
                setcolor(WHITE);
                if (coinprnt(play_ground, player_i, player_j, coin) != -33) {
                    coin = coinprnt(play_ground, player_i, player_j, coin);
                     Beep(1500,300);
                    play_ground[player_i][player_j] = 1;
                }
            }
if (play_ground[player_i][player_j]<=40)
    looper(player_i,player_j);
            entering(num);
            play_change();
          ;break;
        case KEY_UP:

            moves++;
            if (play_ground[player_i][player_j - 1] == 0) {
                setcolor(WHITE);
                outtextxy(450, 40, "No move!");
            Beep(800,150);
            } else {
                Beep(200,150);
                setcolor(BLACK);
                for (i = 0; i < 10; i++) {
                    circle(30 + (20 * player_i), 30 + (20 * player_j), i);

                }
                for (q = 0; q < 20; q++) {
                    setcolor(BLACK);
                    for (i = 0; i < 10; i++) {
                        arc(30 + (20 * player_i), 30 - q + (20 * player_j), -240, 60, i);

                    }
                    setcolor(LIGHTGREEN);
                    for (i = 0; i < 10; i++) {
                        arc(30 + (20 * player_i), 29 - q + (20 * player_j), -240, 60, i);
                    }
                    setcolor(BLACK);
                    for (i = 0; i < 3; i++) {
                        circle(25 + (20 * player_i), 29 - q + (20 * player_j), i);

                    }
                    delay(1);
                }

                player_j--;
                setcolor(WHITE);
                if (coinprnt(play_ground, player_i, player_j, coin) != -33) {
                    coin = coinprnt(play_ground, player_i, player_j, coin);
                     Beep(1500,300);
                    play_ground[player_i][player_j] = 1;
                }
            }
if (play_ground[player_i][player_j]<=40)
    looper(player_i,player_j);
            entering(num);
            play_change();

            ;break;
        case KEY_DOWN:


            moves++;
            if (play_ground[player_i][player_j + 1] == 0) {
                setcolor(WHITE);
                outtextxy(450, 40, "No move!");
            Beep(800,150);
            } else {
                Beep(200,150);
                setcolor(BLACK);
                for (i = 0; i < 10; i++) {
                    circle(30 + (20 * player_i), 30 + (20 * player_j), i);

                }
                for (q = 0; q < 20; q++) {
                    setcolor(BLACK);
                    for (i = 0; i < 10; i++) {
                        arc(30 + (20 * player_i), 30 + q + (20 * player_j), -60, 240, i);

                    }
                    setcolor(LIGHTGREEN);
                    for (i = 0; i < 10; i++) {
                        arc(30 + (20 * player_i), 31 + q + (20 * player_j), -60, 240, i);
                    }
                    setcolor(BLACK);
                    for (i = 0; i < 3; i++) {
                        circle(35 + (20 * player_i), 31 + q + (20 * player_j), i);

                    }
                    delay(1);
                }

                player_j++;
                setcolor(WHITE);
                if (coinprnt(play_ground, player_i, player_j, coin) != -33) {
                    coin = coinprnt(play_ground, player_i, player_j, coin);
                     Beep(1500,300);
                    play_ground[player_i][player_j] = 1;
                }
            }
if (play_ground[player_i][player_j]<=40)
    looper(player_i,player_j);
            entering(num);
            play_change();
       ;break;
        }
    }

    int coll;
    play_ground[player_i][player_j] = (play_ground[player_i][player_j]>50)?
    play_ground[player_i][player_j]-10 : play_ground[player_i][player_j];
    switch (play_ground[player_i][player_j]) {
        case 41:
            setcolor(LIGHTRED);
            coll = 12;
            break;
        case 42:
            setcolor(LIGHTMAGENTA);
            coll = 13;
            break;
        case 43:
            setcolor(LIGHTCYAN);
            coll = 11;
            break;
        case 44:
            setcolor(LIGHTGRAY);
            coll = 7;
            break;
    }
Beep(2000,1000);
    if (coin_num == coin) {
        cleardevice();
        setactivepage(0);
        int p = 0;
        for (i = 10000; i < 100000; i++) {
            putpixel(320 + ((i / 100) * cos(p)), 240 + ((i / 100) * sin(p)), 14);
            p++;
        }
        setcolor(YELLOW);
        outtextxy(235, 220, "Congratulations! You Won!");
        delay(1000);
        coinprnt(play_ground, -1, -1, coin);
         delay(1000);
        printmoves(moves);

    } else if (play_ground[player_i][player_j] == 41) {
        cleardevice();
        setactivepage(0);
        int p = 0;
        for (i = 10000; i < 100000; i++) {
            putpixel(320 + ((i / 100) * cos(p)), 240 + ((i / 100) * sin(p)), coll);
            p++;
        }
        outtextxy(285, 195, "Game over!");
        outtextxy(245, 220, "Blinky Caught Pac Man!");
        delay(1000);
        coinprnt(play_ground, -1, -1, coin);
         delay(1000);
        printmoves(moves);
    } else if (play_ground[player_i][player_j] == 42) {
        cleardevice();
        setactivepage(0);
        int p = 0;
        for (i = 10000; i < 100000; i++) {
            putpixel(320 + ((i / 100) * cos(p)), 240 + ((i / 100) * sin(p)), coll);
            p++;
        }
        outtextxy(285, 195, "Game over!");
        outtextxy(250, 220, "Pinky Caught Pac Man!");
        delay(1000);
        coinprnt(play_ground, -1, -1, coin);
         delay(1000);
        printmoves(moves);
    } else if (play_ground[player_i][player_j] == 43) {
        cleardevice();
        setactivepage(0);
        int p = 0;
        for (i = 10000; i < 100000; i++) {
            putpixel(320 + ((i / 100) * cos(p)), 240 + ((i / 100) * sin(p)), coll);
            p++;
        }
        outtextxy(285, 195, "Game over!");
        outtextxy(255, 220, "Inky Caught Pac Man!");
        delay(1000);
        coinprnt(play_ground, -1, -1, coin);
         delay(1000);
        printmoves(moves);
    } else if (play_ground[player_i][player_j] == 44) {
        cleardevice();
        setactivepage(0);
        int p = 0;
        for (i = 10000; i < 100000; i++) {
            putpixel(320 + ((i / 100) * cos(p)), 240 + ((i / 100) * sin(p)), coll);
            p++;
        }
        outtextxy(285, 195, "Game over!");
        outtextxy(250, 220, "Clyde Caught Pac Man!");

        delay(1000);
        coinprnt(play_ground, -1, -1, coin);
        delay(1000);
        printmoves(moves);
    }
    delay(20000);

    getch();
    closegraph();
}
