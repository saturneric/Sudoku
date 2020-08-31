//
//  main.c
//  Numberonly
//
//  Created by Eric on 15-7-3.
//  Copyright (c) 2015年 Eric. All rights reserved.
//

#include <stdio.h>

int Deal(int *Ableint, int *dtable, int *dwcount);

int main(void) {
    FILE* fp;
    int table[9][9], xtable[9][9][10], ytable[9][9];
    int ycount = 81;
    for(int x = 0;x < 9;x++){
        for (int y =0; y < 9; y++)
        {
            table[x][y] = 0;
            ytable[x][y] = 0;
            for (int z = 0;z <= 9;z++) {
               xtable[x][y][z] = 1;
               xtable[x][y][0] = 0;
            }
        }
    }
    
    fp = fopen("Numberonlyread","r");
    if (fp == NULL) {
        printf("Error in open file.\n");
    }
    else printf("Succeed in open the file.\n");
    
    printf("Read the file...");
    for(int x = 0; x < 9; x++)
        for(int y = 0; y < 9; y++)
            fscanf(fp, "%1d", &table[x][y]);
    
    for(int x = 0; x < 9; x++)
        for(int y = 0; y < 9; y++){
            if(table[x][y] != 0) {
                ytable[x][y] = 1;
                ycount -= 1;
            }
        }
    printf("Succeed in read the file.\n");
    fclose(fp);
    printf("Deal with the data...\n");
    for(int x = 0; x < 9; x++){
        for (int y =0; y < 9; y++){
            
            if (table[x][y] != 0){
                for (int i = 0; i < 9; i++) {
                    xtable[x][i][table[x][y]] = 0;
                    xtable[i][y][table[x][y]] = 0;
                }
                
                int xtemp = (int)(x/3), xnumber = 0;
                int ytemp = (int)(y/3), ynumber = 0;
                
                switch (xtemp) {
                    case 0:
                        xnumber = 0;
                        break;
                    case 1:
                        xnumber = 3;
                        break;
                    case 2:
                        xnumber = 6;
                    default:
                        break;
                }
                
                switch (ytemp) {
                    case 0:
                        ynumber = 0;
                        break;
                    case 1:
                        ynumber = 3;
                        break;
                    case 2:
                        ynumber = 6;
                    default:
                        break;
                }
                for (int i = xnumber; i < xnumber + 3; i++)
                    for (int j = ynumber; j < ynumber + 3; j++)
                        xtable [i][j][table[x][y]] = 0;
                
                
            }
        }
    }
    int finish = 1, wcount = 0, wexit = 0, ecount = 0;;
    while(wcount < ycount && wexit == 0)
    {
        int finish = 0;
        for(int x = 0; x < 9; x++)
            for(int y = 0; y < 9; y++){
                int count = 0, ctemp = 0;
                if (ytable[x][y] != 1)
                {
                    for (int z = 1; z<=9; z++){
                        if (xtable[x][y][z] == 1){
                            count += 1;
                            ctemp = z;
                        }
                    }
                    if (count == 1){
                        table[x][y] = ctemp;
                        printf("Table [%d] [%d] = %d \n",x,y,ctemp);
                        for (int i = 0; i < 9; i++) {
                            xtable[x][i][table[x][y]] = 0;
                            xtable[i][y][table[x][y]] = 0;
                        }
                        
                        int xtemp = (int)(x/3), xnumber = 0;
                        int ytemp = (int)(y/3), ynumber = 0;
                        
                        switch (xtemp) {
                            case 0:
                                xnumber = 0;
                                break;
                            case 1:
                                xnumber = 3;
                                break;
                            case 2:
                                xnumber = 6;
                            default:
                                break;
                        }
                        
                        switch (ytemp) {
                            case 0:
                                ynumber = 0;
                                break;
                            case 1:
                                ynumber = 3;
                                break;
                            case 2:
                                ynumber = 6;
                            default:
                                break;
                        }
                        for (int i = xnumber; i < xnumber + 3; i++)
                            for (int j = ynumber; j < ynumber + 3; j++)
                                xtable [i][j][table[x][y]] = 0;
                        wcount +=1;
                        ecount +=1;
                        
                    }
                }

            }
        if (ecount == 0) {
            wexit = 1;
        }
    }
    
    fp = fopen("Numberonlywrite","w");
    for (int x = 0; x < 9; x++){
        for (int y = 0; y < 9; y++) {
            fprintf(fp,"%d",table[x][y]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 0;
}

int Deal(int *Ableint, int *dtable, int *dwcount){
    
    return 0;
}
