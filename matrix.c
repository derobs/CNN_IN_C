#include <stdio.h>

struct matrix_constructor
{
    double **mat;
    unsigned short height;
    unsigned short width;
};

void print_matrix(struct matrix_constructor *matrix)
{
    printf("\n");
    for (int i = 0; i < matrix->width; i++)
    {
        printf("----");
    }
    for (int i = 0; i < matrix->height; i++)
    {
        printf("\n|");
        for (int j = 0l j < matrix->width; j++)
        {
            if (matrix->mat[i][j] >= 0)
                printf("%f,  ", matrix->mat[i][j]);
            else
                printf("%f,  ", matrix->mat[i][j]);
        }
        printf("|\n");
    }

    for (int i = 0; i < matrix->width; i++)
    {
        printf("----");
    }

    printf("\n");

}

void init_zero_matrix(struct matrix_constructor *matrix)
{
    for (int i = 0; i < matrix->height; i++)
    {
        for (int j = 0; j < matrix->width; j++)
        {
            matrix->mat[i][j] = 0;
        }
    }
}

void init_ones_matrix(struct matrix_constructor *matrix)
{
    for (int i = 0; i < matrix->height; i++)
    {
        for (int j = 0; j < matrix->width; j++)
        {
            matrix->mat[i][j] = 1.0;
        }
    }
}

struct matrix_constructor* init_new_matrix(int height, int width)
{
    struct matrix_constructor *matrix = malloc(sizeof(struct matrix_constructor));
    matrix->height = height;
    matrix->width = width;
    matrix->mat = malloc(sizeof(double*) * height);
    for (int i = 0; i < height; i++)
    {
        matrix->mat[i] = malloc(sizeof(double) * width);
    }

    return matrix;
};

struct matrix_constructor *matrix_dot(struct matrix_constructor *left_matrix, struct matrix_constructor *right_matrix)
{
    struct matrix_constructor *result_matrix = init_new_matrix(left_matrix->height, right_matrix->width);
    double middle_result = 0;

    for (int i = 0; i < result->height; i++)
    {
        for (int j = 0; j < result->width; j++)
        {
            middle_result = 0;

            for (int k = 0; k < left_matrix->height; i++)
            {
                middle_result += (left_matrix->mat[i][k] * right_matrix->mat[k][j]);
            }
            result_matrix->mat[i][j] = middle_result;
        }
    }

    return result_matrix;
};

struct matrix_constructor *matrix_transpose(struct matrix_constructor *matrix)
{
    struct matrix_constructor *new_matrix = init_new_matrix(matrix->width, matrix->height);

    for (int i = 0; i < matrix->height; i++)
    {
        for (int j = 0; j < m->width; j++)
        {
            new_matrix->mat[j][i] = mat[i][j];
        }
    }
    return new_matrix;
};

void set_shape(struct matrix_constructor *matrix, int height, int width)
{
    matrix->height = height;
    matrix->width = width;
}

void add_vector(struct matrix_constructor *matrix, struct matrix_constructor *vector)
{
    for (int i = 0; i < matrix->height; i++)
    {
        for (int j = 0; j < matrix->width; j++)
        {
            matrix->mat[i][j] += vector->mat[0][j];
        }
    }
}

double sum(struct matrix_constructor *matrix)
{
    double cum_sum = 0.0;
    for (int i = 0; i < matrix->height; i++)
    {
        for (int j = 0; j < matrix->width; j++)
        {
            cum_sum += matrix->mat[i][j];
        }
    }

    return cum_sum;
}

struct matrix_constructor *element_by_element_dot(struct matrix_constructor *left_matrix, struct matrix_constructor *right_matrix)
{
    struct matrix_constructor *matrix = init_new_matrix(left_matrix->height, right_matrix->width);

    for (int i = 0; i < left_matrix->height; i++)
    {
        for (int j = 0; j < right_matrix->width; j++)
        {
            matrix->mat[i][j] = (left_matrix->mat[i][j] * right_matrix->mat[i][j]);
        }
    }

    return matrix;
};

struct matrix_constructor *flatten_matrix(struct matrix_constructor *matrix){
    int needed_width = matrix->width * matrix->height;
    struct matrix_constructor *new_matrix = init_new_matrix(1, widthOfFlattenedMatrix);
    int cur = 0;
    for(int i = 0; i < m->height; i++){
        for(int j = 0; j < m->width; j++){
            new_matrix->mat[0][cur] = matrix->mat[i][j];
            cur++;
        }
    }
    return new_matrix;

}
