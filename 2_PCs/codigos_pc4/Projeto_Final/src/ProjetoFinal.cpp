#include "ProjetoFinal.h"

void Tomar_Decisao(struct Decisao *decisao) {
	if ((decisao->navegar && decisao->selecionar && decisao->voltar) != 1) {
		if (decisao->opcao_anterior == 0) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 1;
			} else if (decisao->selecionar == 0) {
				decisao->opcao_atual = 2;
			}
		}

		else if (decisao->opcao_anterior == 1) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 0;
			} else if (decisao->selecionar == 0) {
				decisao->opcao_atual = 7;
			}
		} else if (decisao->opcao_anterior == 2) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 3;
			} else if (decisao->selecionar == 0) {
				//Cadastrar_Turma()
				decisao->opcao_atual = 0; //por enquanto nao esta configurado
				//vai voltar para a tela inicial
			} else if (decisao->voltar == 0) {
				decisao->opcao_atual = 0;
			}
		} else if (decisao->opcao_anterior == 3) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 4;
			} else if (decisao->selecionar == 0) {
				//Ver_Turmas()
				decisao->opcao_atual = 0; //por enquanto nao esta configurado
				//vai voltar para a tela inicial
			} else if (decisao->voltar == 0) {
				decisao->opcao_atual = 0;
			}
		} else if (decisao->opcao_anterior == 4) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 5;
			} else if (decisao->selecionar == 0) {
				//Excluir_Turma()
				decisao->opcao_atual = 0; //por enquanto nao esta configurado
				//vai voltar para a tela inicial
			} else if (decisao->voltar == 0) {
				decisao->opcao_atual = 0;
			}
		} else if (decisao->opcao_anterior == 5) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 6;
			} else if (decisao->selecionar == 0) {
				//Cadastrar_Aluno()
				decisao->opcao_atual = 0; //por enquanto nao esta configurado
				//vai voltar para a tela inicial
			} else if (decisao->voltar == 0) {
				decisao->opcao_atual = 0;
			}
		} else if (decisao->opcao_anterior == 6) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 2;
			} else if (decisao->selecionar == 0) {
				//Excluir_Aluno();
				decisao->opcao_atual = 2; //por enquanto nao esta configurado
				//vai voltar para a tela inicial
			} else if (decisao->voltar) {
				decisao->opcao_atual = 2;
			}
		} else if (decisao->opcao_anterior == 7) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 8;
			} else if (decisao->selecionar == 0) {
				//Registrar_Presenca()
				decisao->opcao_atual = 1; //ainda nao configurado
			} else if (decisao->voltar == 1) {
				decisao->opcao_atual = 1;
			}
		} else if (decisao->opcao_anterior == 8) {
			if (decisao->navegar == 0) {
				decisao->opcao_atual = 7;
			} else if (decisao->selecionar == 0) {
				//Ver Presencas()
				decisao->opcao_atual = 1; //ainda nao configurado
			} else if (decisao->voltar == 0) {
				decisao->opcao_atual = 1;
			}
		}
	}
}

void Realizar_Acao(struct Decisao *decisao, Display *display) {

	if (decisao->opcao_anterior != decisao->opcao_atual) {
		if (decisao->opcao_atual == 0) {
			Acao_Display(display, "1. Op Prof (x)", "2. Op Alu ( )");
		} else if (decisao->opcao_atual == 1) {
			Acao_Display(display, "1. Op Prof ( )", "2. Op Alu (x)");
		} else if (decisao->opcao_atual == 2) {
			Acao_Display(display, "Cad Turma (x)", "Ver Turmas ( )");
		} else if (decisao->opcao_atual == 3) {
			Acao_Display(display, "Cad Turma ( )", "Ver Turmas (x)");
		} else if (decisao->opcao_atual == 4) {
			Acao_Display(display, "Excl Turma (x)", "Cad Aluno ( )");
		} else if (decisao->opcao_atual == 5) {
			Acao_Display(display, "Excl Turma ( )", "Cad Aluno (x)");
		} else if (decisao->opcao_atual == 6) {
			Acao_Display(display, "Excl Aluno (x)", "Voltar...");
		} else if (decisao->opcao_atual == 7) {
			Acao_Display(display, "Reg Pres (x)", "Ver Pres ( )");
		} else if (decisao->opcao_atual == 8) {
			Acao_Display(display, "Reg Pres ( )", "Ver Pres (x)");
		}
		decisao->opcao_anterior = decisao->opcao_atual;
	}
}

void Acao_Display(Display *display, char *str1, char *str2) {
	display->Command("Clear screen");
	display->Command("Go to first line");
	display->Print(str1);
	display->Command("Activate second line");
	display->Command("Go to second line");
	display->Command("LCD ON, Cursor ON, Cursor blinking ON");
	display->Print(str2);
	display->Command("Display ON ,Cursor blinking OFF");

}


