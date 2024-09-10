/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    int left=0;
    int right=n;
    int top=0;
    int bottom=m;
    int** res = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            res[i][j] = -1; // Initialize with -1 or any invalid value
        }
    }

    while (head) {
        // Left to right
        for (int i = left; i < right; i++) {
            if (!head) break;
            res[top][i] = head->val;
            head = head->next;
        }
        top++;

        // Top to bottom
        for (int i = top; i < bottom; i++) {
            if (!head) break;
            res[i][right - 1] = head->val;
            head = head->next;
        }
        right--;

        // Right to left
        for (int i = right - 1; i >= left; i--) {
            if (!head) break;
            res[bottom - 1][i] = head->val;
            head = head->next;
        }
        bottom--;

        // Bottom to top
        for (int i = bottom - 1; i >= top; i--) {
            if (!head) break;
            res[i][left] = head->val;
            head = head->next;
        }
        left++;
    }
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return res;
    
}
