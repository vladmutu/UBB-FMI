"""
Acest modul contine sortarile cerute:
Selection sort
Shake sort
"""


def cmp_date(a, b):
    if a.get_event_date_year() > b.get_event_date_year():
        return True
    elif a.get_event_date_year() == b.get_event_date_year():
        if a.get_event_date_month() > b.get_event_date_month():
            return True
        elif a.get_event_date_month() == b.get_event_date_month():
            if a.get_event_date_day() > b.get_event_date_day():
                return True
            elif a.get_event_data_day() == b.get_event_date_day():
                return True
    return False


def cmp_description(a, b):
    if a.get_event_description() > b.get_event_description():
        return True
    return False


def cmp(a, b):
    if a.get_event_description() > b.get_event_description():
        return True
    elif a.get_event_description == b.get_event_description():
        if a.get_event_length() > b.get_event_length():
            return True
        elif a.get_event_length() == b.get_event_lenght():
            if cmp_date(a, b):
                return True
    return False


def min_index(a, i, j):
    if i == j:
        return i
    k = min_index(a, i + 1, j)
    if cmp(a[i], a[k]):
        return i
    else:
        return k


def recursive_selection_sort(a, n, index=0):
    if index == n:
        return -1
    k = min_index(a, index, n - 1)
    if k != index:
        a[k], a[index] = a[index], a[k]
    recursive_selection_sort(a, n, index + 1)


def cocktail_sort(a):
    n = len(a)
    swapped = True
    start = 0
    end = n - 1
    while swapped:
        swapped = False
        for i in range(start, end):
            if cmp_date(a[i], a[i+1]):
                aux = a[i]
                a[i] = a[i+1]
                a[i+1] = aux
                swapped = True
        if not swapped:
            break
        swapped = False
        end = end - 1
        for i in range(end - 1, start - 1, -1):
            if cmp_date(a[i], a[i+1]):
                aux = a[i]
                a[i] = a[i + 1]
                a[i + 1] = aux
                swapped = True
        start = start + 1
    return a
