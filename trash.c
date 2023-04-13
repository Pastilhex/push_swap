/*
 	//A < B / A < C / B < C
	if (list_a->value < list_a->next->value && list_a->next->value < sort->last_value && list_a->next->value < sort->last_value)
		ra(sort, header_a, 0);
	//A < B / A < C / B > C
	else if (list_a->value < list_a->next->value && list_a->value < sort->last_value && list_a->next->value > sort->last_value && list_a->value == sort->smallest && list_a->next->value == sort->biggest)
		if (size_list(header_a) > 3)
			sa(header_a, 0);
		else
			rra(sort, header_a, 0);
	//A < B / A < C / B > C
	else if (list_a->value < list_a->next->value && list_a->value < sort->last_value && list_a->next->value > sort->last_value)
		pa(header_a, header_b);
	//A < B / A > C / B < C
	else if (list_a->value < list_a->next->value && list_a->value > sort->last_value && list_a->next->value < sort->last_value)
	{
		printf("Wait\n");
		sleep(1);
	}
	//A < B / A > C / B > C
	else if (list_a->value < list_a->next->value && list_a->value > sort->last_value && list_a->next->value > sort->last_value)
		rra(sort, header_a, 0);
	//A > B / A < C / B < C
	else if (list_a->value > list_a->next->value && list_a->value < sort->last_value && list_a->next->value < sort->last_value)
		sa(header_a, 0);
	//A > B / A < C / B > C
	else if (list_a->value > list_a->next->value && list_a->value < sort->last_value && list_a->next->value > sort->last_value)
	{
		printf("Wait\n");
		sleep(1);
	}	//A > B / A > C / B < C
	else if (list_a->value > list_a->next->value && list_a->value > sort->last_value && list_a->next->value < sort->last_value)
		ra(sort, header_a, 0);
	//A > B / A > C / B > C
	else if (list_a->value > list_a->next->value && list_a->value > sort->last_value && list_a->next->value > sort->last_value)
		sa(header_a, 0);	
 */