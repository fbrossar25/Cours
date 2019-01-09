import { Component, OnInit } from '@angular/core';
import { Prestation } from 'src/app/shared/model/prestation';
import { PrestationsService } from '../../services/prestations.service';

@Component({
  selector: 'app-liste-prestations',
  templateUrl: './liste-prestations.component.html',
  styleUrls: ['./liste-prestations.component.scss']
})
export class ListePrestationsComponent implements OnInit {
  collection: Prestation[];
  listHeaders1: string[] = [
    '#',
    'Intitulé',
    'Date de début',
    'Date de fin',
    'Nombre de jours',
    'Tarif journée HT',
    'Taux TVA',
    'Total HT',
    'Total TTC',
    'État',
    'Type'
  ];
  // Injection automatique
  constructor(private prestationsService: PrestationsService) {
    this.collection = this.prestationsService.getCollection();
   }

  ngOnInit() {
  }

}
