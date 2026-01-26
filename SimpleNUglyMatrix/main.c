#define _CRT_SECURE_NO_WARNINGS 1
#include "matrix.h"

#define MAX_MATRICES 10

void ShowMenu() {
    printf("\n========== 矩阵计算器主菜单 ==========\n");
    printf("1. 创建矩阵        2. 随机初始化\n");
    printf("3. 手动输入        4. 打印矩阵\n");
    printf("5. 矩阵加法        6. 矩阵减法\n");
    printf("7. 矩阵乘法        8. 矩阵转置\n");
    printf("9. 求逆矩阵        10. 计算行列式\n");
    printf("11. 计算平均值     12. 查找最大值\n");
    printf("13. 矩阵归一化     14. 提取子矩阵\n");
    printf("15. 删除矩阵       0. 退出\n");
    printf("======================================\n");
}

int SelectMatrix(const char* prompt, Matrix matrices[], int count) {
    if (count == 0) {
        printf("错误：当前没有矩阵！\n");
        return -1;
    }
    printf("\n当前矩阵列表：\n");
    for (int i = 0; i < count; i++) {
        printf("  Matrix[%d] (%d×%d)\n", i, matrices[i].row, matrices[i].col);
    }
    int idx;
    printf("%s >> ", prompt);
    scanf("%d", &idx);
    if (idx < 0 || idx >= count) {
        printf("错误：索引超出范围！\n");
        return -1;
    }
    return idx;
}

int main() {
    Matrix matrices[MAX_MATRICES];
    int count = 0;
    int choice;

    printf("=== 矩阵计算器已启动 ===\n");

    while (1) {
        ShowMenu();
        printf("\n请选择操作 >> ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("\n正在清理资源并退出...\n");
            for (int i = 0; i < count; i++) {
                DestroyMatrix(&matrices[i]);
            }
            break;
        }

        switch (choice) {
        case 1: {
            if (count >= MAX_MATRICES) {
                printf("错误：矩阵数量已达上限(%d)!\n", MAX_MATRICES);
                break;
            }
            printf("\n创建 Matrix[%d]:\n", count);
            InitialMatrixRowCol(&matrices[count]);
            InitialMatrix(&matrices[count]);
            count++;
            printf("成功：矩阵已创建！\n");
            break;
        }

        case 2: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx >= 0) InitialMatrixRand(&matrices[idx]);
            break;
        }

        case 3: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx >= 0) InputMatrix(&matrices[idx]);
            break;
        }

        case 4: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx >= 0) PrintMatrix(&matrices[idx]);
            break;
        }

        case 5: {
            int a = SelectMatrix("选择矩阵A", matrices, count);
            if (a < 0) break;
            int b = SelectMatrix("选择矩阵B", matrices, count);
            if (b < 0) break;
            Matrix res;
            if (AddMatrix(&matrices[a], &matrices[b], &res)) {
                printf("\n结果：\n");
                PrintMatrix(&res);
                DestroyMatrix(&res);
            }
            else printf("错误：矩阵维度不匹配！\n");
            break;
        }

        case 6: {
            int a = SelectMatrix("选择矩阵A", matrices, count);
            if (a < 0) break;
            int b = SelectMatrix("选择矩阵B", matrices, count);
            if (b < 0) break;
            Matrix res;
            if (MinusMatrix(&matrices[a], &matrices[b], &res)) {
                printf("\n结果：\n");
                PrintMatrix(&res);
                DestroyMatrix(&res);
            }
            else printf("错误：矩阵维度不匹配！\n");
            break;
        }

        case 7: {
            int a = SelectMatrix("选择矩阵A", matrices, count);
            if (a < 0) break;
            int b = SelectMatrix("选择矩阵B", matrices, count);
            if (b < 0) break;
            Matrix res;
            if (MultiMatrix(&matrices[a], &matrices[b], &res)) {
                printf("\n结果：\n");
                PrintMatrix(&res);
                DestroyMatrix(&res);
            }
            else printf("错误：A的列数必须等于B的行数！\n");
            break;
        }

        case 8: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx >= 0) {
                TransMatrix(&matrices[idx]);
                printf("矩阵已转置！\n");
            }
            break;
        }

        case 9: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx < 0) break;
            if (matrices[idx].row != matrices[idx].col) {
                printf("错误：只有方阵才能求逆！\n");
                break;
            }
            Matrix inv;
            ReverseMatrix(&matrices[idx], &inv);
            if (inv.mat != NULL) {
                printf("\n逆矩阵：\n");
                PrintMatrix(&inv);
                DestroyMatrix(&inv);
            }
            break;
        }

        case 10: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx < 0) break;
            if (matrices[idx].row != matrices[idx].col) {
                printf("错误：只有方阵才有行列式！\n");
                break;
            }
            double det = DeterminantMatrix(&matrices[idx]);
            printf("\n行列式值 = %.6lf\n", det);
            break;
        }

        case 11: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx >= 0) {
                double mean = MeanMatrix(&matrices[idx]);
                printf("\n平均值 = %.6lf\n", mean);
            }
            break;
        }

        case 12: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx >= 0) {
                double max = MaxMatrix(&matrices[idx]);
                printf("\n最大值 = %.6lf\n", max);
            }
            break;
        }

        case 13: {
            int idx = SelectMatrix("选择矩阵", matrices, count);
            if (idx >= 0) {
                NormMatrix(&matrices[idx]);
                printf("矩阵已归一化！\n");
            }
            break;
        }

        case 14: {
            int idx = SelectMatrix("选择源矩阵", matrices, count);
            if (idx < 0) break;
            if (count >= MAX_MATRICES) {
                printf("错误：矩阵数量已达上限！\n");
                break;
            }
            SubMatrix(&matrices[idx], &matrices[count]);
            count++;
            printf("子矩阵已提取！\n");
            break;
        }

        case 15: {
            if (count == 0) {
                printf("错误：没有矩阵可删除！\n");
                break;
            }
            int idx = SelectMatrix("选择要删除的矩阵", matrices, count);
            if (idx >= 0) {
                DestroyMatrix(&matrices[idx]);
                for (int i = idx; i < count - 1; i++) {
                    matrices[i] = matrices[i + 1];
                }
                count--;
                printf("矩阵已删除！\n");
            }
            break;
        }

        default:
            printf("错误：无效的选择！\n");
            break;
        }
    }

    return 0;
}